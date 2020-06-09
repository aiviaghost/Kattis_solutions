from sys import stdin, stdout

rhyme = len([i for i in stdin.readline().split(" ")]) - 1

n = int(stdin.readline())

people = []
for i in range(n):
    people.append(stdin.readline())

team1 = []
team2 = []

current_index = rhyme % len(people)
while len(people) > 0:
    team1.append(people.pop((current_index + rhyme) % len(people)))
    if len(people) > 0:
        current_index = (current_index + 2 * rhyme) % len(people)
        #print("1: ", current_index, rhyme, len(people))
    
    if len(people) > 0:
        team2.append(people.pop((current_index) % len(people)))
        current_index = (current_index + 2 * rhyme) % len(people)
        #print("2: ", current_index, rhyme, len(people))

stdout.write(str(len(team1)))
stdout.write("\n")
for i in team1:
    stdout.write(i)

stdout.write(str(len(team2)))
stdout.write("\n")
for i in team2:
    stdout.write(i)
