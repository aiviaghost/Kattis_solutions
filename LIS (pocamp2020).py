def LIS(x):
    L, P = [None] * len(x), [None] * len(x)
    for j in range(len(x)):
        less_idx = [i for i in range(j) if x[i] < x[j]]
        #L[j] = max([1] + [L[i] + 1 for i in less_idx])
        best = None
        max_len = 1
        for i in less_idx:
            if(L[i] + 1 > max_len):
                max_len = L[i] + 1
                best = i
        L[i] = max_len
        P[j] = best
    l = max(L)
    curr = L.index(l)
    res = []
    while(curr != None):
        res.append(x[curr])
        curr = P[curr]
    return reversed(res)
