n = int(input())

count = 0
for _ in range(n):
    b = list(map(int, input().split()))
    if sum(b) >= 2:
        count += 1
print(count)
