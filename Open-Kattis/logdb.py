import re
import sys
from collections import defaultdict

fact_regex = "[a-zA-Z0-9_]+ *\([a-zA-Z0-9,_ ]+\)"

fact_dict = defaultdict(lambda: defaultdict(list))

reading_facts = True

for line in map(str.strip, sys.stdin.readlines()):
    if line == "":
        reading_facts = False
        continue

    if reading_facts:
        for match in re.findall(fact_regex, line):
            sp = match.find("(")
            f_name = match[:sp].strip()
            args = [i.strip() for i in match[sp+1:-1].split(",")]
            fact_dict[f_name][len(args)].append(args)
    else:
        sp = line.find("(")
        f_name = line[:sp].strip()
        args = [i.strip() for i in line[sp+1:-1].split(",")]

        if f_name not in fact_dict or len(args) not in fact_dict[f_name]:
            print(0)
        else:
            names = defaultdict(list)
            variables = defaultdict(list)

            for i, arg in enumerate(args):
                if arg == "_":
                    pass
                elif arg[0] == "_":
                    variables[arg].append(i)
                else:
                    names[arg].append(i)

            ans = 0
            for candidate in fact_dict[f_name][len(args)]:
                valid = True

                for name, positions in names.items():
                    if not all(candidate[i] == name for i in positions):
                        valid = False

                for positions in variables.values():
                    if not all(candidate[i] == candidate[j] for i, j in zip(positions, positions[1:])):
                        valid = False

                if valid:
                    ans += 1

            print(ans)
