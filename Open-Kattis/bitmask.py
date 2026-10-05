target = input()
n = len(target)

cost = list(map(int, input().split()))

masks = [bin(x)[2:].rjust(i, "0") for i in range(1, n + 1) for x in range(2**i)]

INF = 1200

dp = [{} for _ in range(n + 1)]
dp[0] = {tuple(): 0}

for start in range(n):
    for state_so_far, cost_so_far in dp[start].items():
        for mask in masks:
            end = start + len(mask)
            if end <= n and target[start:end] == mask:
                c = 0 if mask in state_so_far else cost[len(mask) - 1]
                new_state = (*state_so_far, mask)
                dp[end][new_state] = min(dp[end].get(new_state, INF), cost_so_far + c)

print(min(dp[-1].values()))
