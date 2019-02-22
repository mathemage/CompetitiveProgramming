n = int(input())

res = None
n -= 10  # queen of spades
if n in range(1, 10) or n == 11:
	res = 4
elif n == 10:
	res = 15
else:
	res = 0

print(res)
