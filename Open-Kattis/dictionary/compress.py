import pickle
import bz2
import lzma
import gzip
import re

class Trie:
    def __init__(self):
        self.is_end = False
        self.children = {}
    
    def insert(self, w, i = 0):
        if i == len(w):
            self.is_end = True
            return
        if w[i] not in self.children:
            self.children[w[i]] = Trie()
        self.children[w[i]].insert(w, i + 1)
        

with open("dict.txt") as f:
    words = f.read().strip().encode().split(b"\n")

T = Trie()
for word in words:
    T.insert(word.replace(b"'s", b"&"))

def dfs(t):
    if len(t.children) == 0:
        return {}
    curr = {}
    for k, v in t.children.items():
        curr[bytes([k + (128 if v.is_end else 0)])] = dfs(v)
    return curr

s = str(dfs(T)).encode().replace(b" ", b"")

"""
with open("original.txt", "w") as f:
    f.write(s)
"""
# s = s.encode()

with open("bin.txt", "wb") as f:
    sub1 = re.sub(
            pattern = b"b\\'[a-zA-Z&']\\'", 
            repl = lambda x: x.group()[2 : -1], 
            string = s
        )
    sub2 = re.sub(
            pattern = b'b"[a-zA-Z\']"', 
            repl = lambda x: x.group()[2 : -1], 
            string = sub1
        ).replace(b"{}", b"").replace(b":", b"").replace(b"''", b"")
    sub3 = re.sub(
        pattern = b"b'[\\a-zA-Z0-9]{4,4}'",
        repl = lambda x: x.group()[4 : -1],
        string = sub2
    )
    f.write(
        gzip.compress(bz2.compress(sub3))
    )
