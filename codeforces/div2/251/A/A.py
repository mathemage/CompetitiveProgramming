n, d = map(int, input().split())
t = list(map(int, input().split()))

jokes = 0
d -= t[0]
for k in t[1:]:
	d -= 10
	jokes += 2
	d -= k

if d >= 0:
	jokes += d // 5
else:
	jokes = -1

print(jokes)
