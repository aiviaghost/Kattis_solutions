from sys import stdin, stdout

n = int(stdin.readline())

books = []
for _ in range(n):
    books.append(int(stdin.readline()))

books.sort(reverse=True)

sum = 0
for i in range(n):
    try:
        if i % 3 == 0 or i % 3 == 1:
            sum += books[i]
    except:
        break

stdout.write(str(sum))
