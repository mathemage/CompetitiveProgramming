k = int(input())
l = int(input())
m = int(input())
n = int(input())
d = int(input())

count = 0
for i in range(1, d + 1):
    if 0 in [i % x for x in [k, l, m, n]]:
        count += 1

print(count)
