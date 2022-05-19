import gzip
import bz2
import re
with open("bin.txt", "rb") as f:
    T = bz2.decompress(
            gzip.decompress(
                f.read()
            )
        ).decode()
sub1 = re.sub(
    pattern = "[a-zA-Z']",
    repl = lambda x: '"' + x.group() + '":',
    string = T
)
sub2 = re.sub(
    pattern = ":}",
    repl = ":{" + "}" + "}",
    string = sub1
)
sub3 = re.sub(
    pattern = ":,",
    repl = ":{" + "},",
    string = sub2
)
di = eval(sub3)
words = []
def dfs(di, curr):
    if len(di) == 0:
        words.append(curr)
        return
    for k, v in di.items():
        dfs(v, curr + k)
dfs(di, "")
with open("test.txt", "w") as f:
    f.write("\n".join(sorted(words)))
print("\n".join(sorted(words)))