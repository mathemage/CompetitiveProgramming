n = int(input())
count = 0
a_prev, b_prev = -1, 0
for _ in range(n):
	a, b = map(int, input().split())
	
	start = max(a_prev, b_prev)
	end = min(a, b)
	if end >= start:
		count += end - start + 1
		if a_prev == b_prev:
			count -= 1
	
	a_prev, b_prev = a, b

print(count)
