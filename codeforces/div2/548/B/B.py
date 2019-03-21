n = int(input())
a = list(map(int, input().split()))

for i in reversed(range(1, n)):
	for j in range(i):
		a[j] = min(a[j], a[i] - 1 if a[i] > 0 else 0)

print(sum(a))
