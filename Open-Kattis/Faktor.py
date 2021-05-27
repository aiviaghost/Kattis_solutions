from sys import stdin, stdout
from math import ceil

A, I = map(int, stdin.readline().split())

initial_guess = A * I

while ceil(initial_guess / A) == I:
    initial_guess -= 1

stdout.write(str(initial_guess + 1))
