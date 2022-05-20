import bz2
import re
import json
with open("/src/bin.txt", "rb") as f:
    T = bz2.decompress(
            f.read()
        ).decode()
sub0 = re.sub(
    pattern = "[a-zA-Z&']a",
    repl = lambda x: '"' + x.group() + '":',
    string = T
)
sub1 = re.sub(
    pattern = "[a-zA-Z&']{",
    repl = lambda x: '"' + x.group()[ : -1] + '":{',
    string = sub0
)
sub2 = re.sub(
    pattern = ":(,|})",
    repl = lambda x: ':{}' + x.group()[1 : ],
    string = sub1
)
di = json.loads(sub2)
words = []
def dfs(di, curr, app = False):
    if app:
        words.append("".join(curr))
    if len(di) == 0:
        return
    for k, v in di.items():
        dfs(v, curr + [k[:1]], len(k) > 1)
dfs(di, [])
print("\n".join(sorted(map(lambda x: x.replace("&", "'s"), words))))