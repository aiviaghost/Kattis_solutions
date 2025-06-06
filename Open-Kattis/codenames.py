from collections import defaultdict

n = int(input())

ss = [input().encode() for _ in range(n)]

adj = [[] for _ in range(n)]


def xor(a, b):
    return bytes(x ^ y for x, y in zip(a, b))


for i in range(n):
    for j in range(i + 1, n):
        diff = list(filter(lambda x: x != 0, xor(ss[i], ss[j])))

        if len(diff) == 2 and diff[0] == diff[1]:
            adj[i].append(j)
            adj[j].append(i)


color = [-1 for _ in range(n)]
components = defaultdict(list)


def two_color(curr, cc, curr_color=0):
    global color

    color[curr] = curr_color
    components[cc].append(curr)

    for next in adj[curr]:
        if color[next] == -1:
            two_color(next, cc, 1 - curr_color)


curr_component = 0
for start in range(n):
    if color[start] == -1:
        two_color(start, curr_component)
        curr_component += 1


# Hopcroft-Karp bipartite max-cardinality matching and max independent set
# David Eppstein, UC Irvine, 27 Apr 2002
# Used in https://open.kattis.com/problems/cuckoo
def bipartiteMatch(graph):
    """Find maximum cardinality matching of a bipartite graph (U,V,E).
    The input format is a dictionary mapping members of U to a list
    of their neighbors in V.  The output is a triple (M,A,B) where M is a
    dictionary mapping members of V to their matches in U, A is the part
    of the maximum independent set in U, and B is the part of the MIS in V.
    The same object may occur in both U and V, and is treated as two
    distinct vertices if this happens."""

    # initialize greedy matching (redundant, but faster than full search)
    matching = {}
    for u in graph:
        for v in graph[u]:
            if v not in matching:
                matching[v] = u
                break

    while 1:
        # structure residual graph into layers
        # pred[u] gives the neighbor in the previous layer for u in U
        # preds[v] gives a list of neighbors in the previous layer for v in V
        # unmatched gives a list of unmatched vertices in final layer of V,
        # and is also used as a flag value for pred[u] when u is in the first layer
        preds = {}
        unmatched = []
        pred = dict([(u, unmatched) for u in graph])
        for v in matching:
            del pred[matching[v]]
        layer = list(pred)

        # repeatedly extend layering structure by another pair of layers
        while layer and not unmatched:
            newLayer = {}
            for u in layer:
                for v in graph[u]:
                    if v not in preds:
                        newLayer.setdefault(v, []).append(u)
            layer = []
            for v in newLayer:
                preds[v] = newLayer[v]
                if v in matching:
                    layer.append(matching[v])
                    pred[matching[v]] = v
                else:
                    unmatched.append(v)

        # did we finish layering without finding any alternating paths?
        if not unmatched:
            unlayered = {}
            for u in graph:
                for v in graph[u]:
                    if v not in preds:
                        unlayered[v] = None
            return (matching, list(pred), list(unlayered))

        # recursively search backward through layers to find alternating paths
        # recursion returns true if found path, false otherwise
        def recurse(v):
            if v in preds:
                L = preds[v]
                del preds[v]
                for u in L:
                    if u in pred:
                        pu = pred[u]
                        del pred[u]
                        if pu is unmatched or recurse(pu):
                            matching[v] = u
                            return 1
            return 0

        for v in unmatched:
            recurse(v)


ans = 0
for component in components.values():
    graph = defaultdict(list)
    for a in component:
        if color[a] == 0:
            for next in adj[a]:
                graph[a].append(next)

    M, _, _ = bipartiteMatch(graph)
    num_covered_nodes = 2 * len(M)
    num_edges = len(M.items())

    ans += num_edges + (len(component) - num_covered_nodes)

print(ans)
