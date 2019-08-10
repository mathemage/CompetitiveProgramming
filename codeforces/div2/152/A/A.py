n = int(input())
count01 = 0
count10 = 1
for _ in range(n):
    l, r = map(int, input().split())
    if l == 0:
        count10 += 1
    if l == 1:
        count01 += 1
    if r == 0:
        count01 += 1
    if r == 1:
        count10 += 1

print(min(count01, count10))
