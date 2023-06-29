T = int(input())

for t in range(1, T + 1):
    alien_number, source_lang, target_lang = input().split()
    dec = 0
    for exp, c in enumerate(alien_number[::-1]):
        dec += source_lang.index(c) * len(source_lang) ** exp
    ans = []
    while dec > 0:
        ans.append(target_lang[dec % len(target_lang)])
        dec //= len(target_lang)
    ans = "".join(ans[::-1])
    print(f"Case #{t}: {''.join(ans)}")
