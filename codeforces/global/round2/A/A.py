n = int(input())
c = list(map(int, input().split()))

result = None if c[0] == c[-1] else n - 1
if not result:
	# head
	i = n - 1
	while c[i] == c[0]:
		i -= 1
	d_l = i

	# tail
	i = 0
	while c[i] == c[-1]:
		i += 1
	d_r = n - 1 - i

	result = max(d_l, d_r)
print(result)
