au, bu, ar, br = map(int, input().split())

total = ar * br

if au < bu:
	total += au
	if ar > 0:
		total += bu - au
	print(max(total, ar * br + (au if br > 0 else 0) + (bu if ar > 0 else 0)))
else:
	total += bu
	if br > 0:
		total += au - bu
	print(max(total, ar * br + (au if br > 0 else 0) + (bu if ar > 0 else 0)))
