from sys import stdin as cin, stdout as cout

T = int(cin.readline())

for _ in range(T):
    n = int(cin.readline())
    results = [int(i) for i in cin.readline().split()]
    results = sorted(results)

    left_index, right_index, s = 0, len(results) - 2, 0
    while left_index < right_index:
        s = s + results[right_index]
        left_index += 1
        right_index -= 2
    
    cout.write(str(s) + "\n")
