from sys import stdin, stdout

n = int(stdin.readline())

exps = [int(i) for i in stdin.readline().rstrip().split()]

curr = 1
ans = ""
for i in exps:
    curr *= 2
    curr -= i

    if curr < 0:
        ans = "error"
        break

print(int(curr % 1000000007) if ans == "" else ans)
