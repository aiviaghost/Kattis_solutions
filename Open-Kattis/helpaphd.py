for _ in range(int(input())):
    print(eval(expr) if (expr := input()) != "P=NP" else "skipped")
