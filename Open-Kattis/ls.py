def matches(s, P):
    N = len(s)
    M = len(P)
    dp = {}
    
    def __matches(i, j):
        if i >= N and j >= M:
            return True

        if i < N and j >= M:
            return False

        if i >= N:
            if P[j] != "*":
                return False
            return __matches(i, j + 1)

        if (i, j) in dp:
            return dp[i, j]

        valid = False

        if s[i] == P[j]:
            valid |= __matches(i + 1, j + 1)
        
        if P[j] == "*":
            valid |= __matches(i, j + 1)
            valid |= __matches(i + 1, j)

        dp[i, j] = valid

        return valid
    
    return __matches(0, 0)

P = input()
for _ in range(int(input())):
    s = input()
    if matches(s, P):
        print(s)
