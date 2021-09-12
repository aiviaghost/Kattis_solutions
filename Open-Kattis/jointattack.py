from sys import stdin, stdout
from math import gcd


class Fraction:
    def __init__(self, a, b = 1):
        self.a = a
        self.b = b

    def __add__(self, other):
        temp = Fraction(self.a * other.b + other.a, other.b)
        return temp // gcd(temp.a, temp.b)
    
    def __mul__(self, other):
        temp = Fraction(self.a * other.a, self.b * other.b)
        return temp // gcd(temp.a, temp.b)
    
    def __truediv__(self, other):
        temp = Fraction(self.a * other.b, self.b * other.a)
        return temp // gcd(temp.a, temp.b)

    def __floordiv__(self, div):
        return Fraction(self.a // div, self.b // div)
    
    def __str__(self):
        return f"{self.a}/{self.b}"


def simplify(co, i = 0):
    if i == len(co) - 1:
        return co[i]
    return co[i] + (Fraction(1) / simplify(co, i + 1))


stdin.readline()
co = [Fraction(int(i)) for i in stdin.readline().split()]
stdout.write(f"{simplify(co)}\n")
