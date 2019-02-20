n1 = input()
n2 = input()

for c1, c2 in zip(n1, n2):
	print('1' if c1 != c2 else '0', end='')
print()
