from z3 import *

s = Solver()

x, y, z = Var("x"), Var("y"), Var("z")

# a + 3b + 3c <= 76

s.add(x * y * z >= 2005)
s.add(x + 3 * y + 3 * z <= 76)

if s.check():
	print(s.model())
