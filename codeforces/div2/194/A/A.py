n = int(input())

s = n * (n ** 2 + 1) // 2
used = [False] * n ** 2
for i in range(1, n + 1):
	current_s = s
	current_bag = []
	k = n ** 2

	while current_s != 0:
		if current_s <= n ** 2 and not used[current_s-1]:
			k = current_s
		if not used[k-1]:
			current_bag.append(k)
			used[k-1] = True
			current_s -= k
		else:
			k -= 1

	print(' '.join(map(str, current_bag)))
