print(sum(int.__sub__(*map(int, p[::-1])) + 1 if len(p := s.split("-")) == 2 else 1 for s in input().split(";")))
