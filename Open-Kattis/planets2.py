p = int(input())

count = {}
species_to_planet = {}

for _ in range(p):
    planet, _, *species = input().split()
    count[planet] = 0
    for specie in species:
        species_to_planet[specie] = planet

v = int(input())
for _ in range(v):
    num, specie = input().split()
    count[species_to_planet[specie]] += int(num)

print("\n".join(f"{planet} {count[planet]}" for planet in sorted(count.keys())))
