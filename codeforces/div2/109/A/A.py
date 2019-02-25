n = int(input())
vals = list(map(int, input().split()))

count = 0
mi = ma = vals[0]
for v in vals[1:]:
	if v < mi:
		mi = v
		count += 1
	if v > ma:
		ma = v
		count += 1

print(count)
