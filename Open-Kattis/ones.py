import sys
for n in sys.stdin.readlines():
    c,a=0,1
    while c:=(10*c+1)%int(n):a+=1
    print(a)