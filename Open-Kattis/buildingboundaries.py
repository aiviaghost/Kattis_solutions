from itertools import permutations

t = int(input())

for _ in range(t):
    a, b, c, d, e, f = map(int, input().split())
    
    ans = 10 ** 30
    for a, b in permutations((a, b)):
        for c, d in permutations((c, d)):
            for e, f in permutations((e, f)):
                for (w1, h1), (w2, h2), (w3, h3) in permutations([(a, b), (c, d), (e, f)]):
                    if h2 > h1:
                        continue
                    w = w1 + w2
                    h = h1
                    if h1 > h2:
                        ans = min(ans, max(w, w1 + w3) * max(h, h3 + h2))
                    else:
                        ans = min(ans, max(w, w3) * (h + h3))
                    ans = min(ans, (w + w3) * max(h, h3))
    
    print(ans)
