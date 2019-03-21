n = int(input())
a = list(map(int, input().split()))

for i in range(1, n):
	for j in range(i):
		a[j] = min(a[j], a[i] - 1)

print(sum(a))
