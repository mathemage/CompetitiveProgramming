n = int(input())
s = input()

result = 0
for i, c in enumerate(s):
	if c in "02468":
		result += i + 1

print(result)
