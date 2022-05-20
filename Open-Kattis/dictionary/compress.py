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
    words = f.read().strip().split("\n")

T = Trie()
for word in words[ : 92000]:
    T.insert(word)

def dfs(t):
    if len(t.children) == 0:
        return {}
    curr = {}
    for k, v in t.children.items():
        curr[k + ("a" if v.is_end else "")] = dfs(v)
    return curr

s = str(dfs(T)).replace(" ", "")

with open("original.txt", "w") as f:
    f.write(s)

s = s.encode()

with open("bin.txt", "wb") as f:
    sub1 = re.sub(
            pattern = b"'[a-zA-Z'](a|)'", 
            repl = lambda x: x.group()[1 : -1], 
            string = s
        )
    sub2 = re.sub(
            pattern = b'"[a-zA-Z\'](a|)"', 
            repl = lambda x: x.group()[1 : -1], 
            string = sub1
        ).replace(b"{}", b"").replace(b":", b"").replace(b"''", b"")
    f.write(
        gzip.compress(bz2.compress(sub2))
    )
