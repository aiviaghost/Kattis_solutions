P = int(input())

def left_ans(p, q):
    pp, pq = p, (q - p)
    ap, aq = pp + pq, pq
    return ap, aq    

out = []
for t in range(1, P + 1):
    pq = input().split()[1]
    p, q = map(int, pq.split("/"))
    if q == 1:
        out.append(f"{t} {1}/{p + 1}")
    elif p < q:
        ap, aq = left_ans(p, q)
        out.append(f"{t} {ap}/{aq}")
    else:
        k = (p - q) // q + 1
        left_p, left_q = p - k * q, q
        right_p, right_q = left_ans(left_p, left_q)
        ans_p, ans_q = right_p, right_q + k * right_p
        out.append(f"{t} {ans_p}/{ans_q}")

print("\n".join(out))
