n = int(input())

d = float(input())

cars = []
for _ in range(n):
    name, v, r = input().split()
    cars.append((name, float(v), float(r)))

print(max(cars, key=lambda car: car[1] / (car[2] / (d / car[1])))[0])
