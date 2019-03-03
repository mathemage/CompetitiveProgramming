n = int(input())
a = list(map(int, input().split()))

histogram = {}
res = 0
for i in range(n-1):
	for j in range(i+1, n):
		s = a[i] + a[j]
		if s not in histogram:
			histogram[s] = 0
		histogram[s] += 1
		res = max(res, histogram[s])
print(res)
