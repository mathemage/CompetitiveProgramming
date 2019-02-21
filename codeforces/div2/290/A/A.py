n, m = map(int, input().split())

img = [['.' for _ in range(m)] for _ in range(n)]

for r in range(n):
	if r % 2 == 0:
		img[r] = ['#'] * m
	else:
		col = -1 if r % 4 == 1 else 0
		img[r][col] = '#'

for row in img:
	print(''.join(row))
