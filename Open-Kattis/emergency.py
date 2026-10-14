n, k = map(int, input().split())

n -= 1

potential_answers = [n]

if n == 0:
    potential_answers.append(0)

if k == 1:
    potential_answers.append(2)

x = n // k
lb = x * k
potential_answers.append(k + 1 + n - lb)

ans = min(potential_answers)
print(ans)
