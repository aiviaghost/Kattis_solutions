from sys import stdin, stdout

def bin_exp(base, exp):
    res = 1
    while (exp > 0):
        if exp % 2 == 1:
            res *= base
        base *= base
        exp >>= 1
    return res

for n in stdin:    
    n = int(n) - 1
    if n == -1:
        break
    
    bin_rep = "{0:b}".format(n)
    subset = []
    for i in range(len(bin_rep) - 1, -1, -1):
        if (bin_rep[i] == "1"):
            subset.append(bin_exp(3, len(bin_rep) - i - 1))
        
    if len(subset) == 0:
        stdout.write("{ }\n")
    else:
        stdout.write("{ ")
        stdout.write(", ".join([str(i) for i in subset]))
        stdout.write(" }\n")
