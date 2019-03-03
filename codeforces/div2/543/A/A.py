n, m, k = map(int, input().split())
p = list(map(int, input().split()))
s = list(map(int, input().split()))
c = list(map(int, input().split()))

res = 0
maxs = [0] * (m + 1)
for pi, si in zip(p, s):
	maxs[si] = max(maxs[si], pi)
for ci in c:
	if p[ci-1] < maxs[s[ci-1]]:
		res += 1
		
print(res)
