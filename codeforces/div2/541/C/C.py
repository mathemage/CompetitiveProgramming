n = int(input())
a = list(map(int, input().split()))

a.sort()
result = a
if n > 3:
	upper, lower = [a[1]], [a[0]]
	for x in a[2:n-1]:
		upper_cost = abs(a[-1] - upper[-1])
		lower_cost = abs(a[-1] - lower[-1])
		if upper_cost > lower_cost:
			upper.append(x)
		else:
			lower.append(x)
	lower.reverse()
	result = upper + [a[-1]] + lower

print(' '.join(map(str, result)))
