from sys import stdin, stdout

d = {
    "clank" : "a",
    "bong" : "b",
    "click" : "c",
    "tap" : "d",
    "poing" : "e",
    "clonk" : "f",
    "clack" : "g",
    "ping" : "h",
    "tip" : "i",
    "cloing" : "j",
    "tic" : "k",
    "cling" : "l",
    "bing" : "m",
    "pong" : "n",
    "clang" : "o",
    "pang" : "p",
    "clong" : "q",
    "tac" : "r",
    "boing" : "s",
    "boink" : "t",
    "cloink" : "u",
    "rattle" : "v",
    "clock" : "w",
    "toc" : "x",
    "clink" : "y",
    "tuc" : "z",
    "whack" : " ",
    "bump" : "capslock",
    "pop" : "delete",
    "dink" : "shift_down",
    "thumb" : "shift_up"
}

n = int(input())

shift_is_down = False
capslock_is_down = False
out = ""
for _ in range(n):
    typed = d[stdin.readline().strip()]
    
    if (typed == "capslock"):
        capslock_is_down = not capslock_is_down
    elif (typed == "shift_down"):
        shift_is_down = True
    elif (typed == "shift_up"):
        shift_is_down = False
    elif (typed == "delete"):
        if (len(out) > 0):
            out = out [ : -1]
    else:
        if (capslock_is_down and shift_is_down):
            out += typed
        elif (capslock_is_down and not shift_is_down):
            out += typed.upper()
        elif (not capslock_is_down and shift_is_down):
            out += typed.upper()
        else:
            out += typed

stdout.write(out + "\n")
