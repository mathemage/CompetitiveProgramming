n, t = map(int, input().split())
s = list(input())

for _ in range(t):
	for i in reversed(range(n - 1)):
		if s[i] == 'B' and s[i + 1] == 'G':
			s[i], s[i + 1] = s[i + 1], s[i]

print(''.join(s))
