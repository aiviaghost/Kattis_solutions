g, s, c = map(int, input().split())

bp = 3 * g + 2 * s + c

if bp < 2:
    print("Copper")
elif bp == 2:
    print("Estate or Copper")
elif bp < 5:
    print("Estate or Silver")
elif bp == 5:
    print("Duchy or Silver")
elif bp < 8:
    print("Duchy or Gold")
else:
    print("Province or Gold")
