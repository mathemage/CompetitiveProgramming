y = int(input())

for k in range(y+1, 10000):
	if len(set(str(k))) == 4:
		print(k)
		break
