current_guess = 500

upper_bound = 1001
lower_bound = 1

for _ in range(10):
    print(current_guess, flush=True)

    answer = input()

    if(answer == "correct"):
        exit()
    elif(answer == "lower"):
        upper_bound = current_guess
    else:
        lower_bound = current_guess
    current_guess = (upper_bound + lower_bound) // 2
