from sys import stdin, stdout

a, b, c, n = map(int, stdin.readline().split())

if a >= 1 and b >= 1 and c >= 1 and 3 <= n <= a + b + c:
    stdout.write("YES")
else:
    stdout.write("NO")
