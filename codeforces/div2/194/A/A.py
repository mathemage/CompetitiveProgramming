n = int(input())

s = n * (n ** 2 + 1) // 2
for i in range(1, n + 1):
	print("{} {}".format(i, s - i))
