import itertools

_, L, C, W = map(int, input().split())

slots = [0] * (L + 1)
for i in map(int, input().split()):
    slots[i] = 1

prefix = list(itertools.accumulate(slots))
def range_sum(lb, rb):
    return prefix[rb] - prefix[lb - 1]

dp_curr = [0] * (L + 1)
for _ in range(C):
    dp_next = [0] * (L + 1)
    for starting_position in range(1, L - W + 2):
        dp_next[starting_position + W - 1] = max(dp_next[starting_position + W - 2], dp_curr[starting_position - 1] + range_sum(starting_position, starting_position + W - 1))
    dp_curr = dp_next

print(dp_curr[-1])
