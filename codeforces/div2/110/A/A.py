n = input()

count = 0
for c in n:
	if c in "47":
		count += 1
		
count = str(count)
answer = "YES"
for c in count:
	if c not in "47":
		answer = "NO"
		break
		
print(answer)
