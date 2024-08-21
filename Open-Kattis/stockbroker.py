d = int(input())

leftover_money = 100
max_money = leftover_money
max_shares = 0

for _ in range(d):
    price = int(input())

    max_money = max(max_money, max_shares * price + leftover_money)

    max_shares = min(max_money // price, 100_000)
    leftover_money = max_money - max_shares * price

print(max_money)
