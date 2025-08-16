def answer(s):
    print(s)
    exit()


N = int(input())
pizzas = [int(input()) for _ in range(N)]

if N == 1:
    answer("Ja" if pizzas[0] % 2 == 0 else "Nej")

if N == 2:
    answer("Ja" if pizzas[0] % 2 == 1 or pizzas[1] % 2 == 1 else "Nej")

answer("Ja" if any(p % 2 == 0 for p in pizzas) else "Nej")
