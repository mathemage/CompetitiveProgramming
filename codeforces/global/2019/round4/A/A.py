n = int(input())
a = list(map(int, input().split()))
partners = a[1:]

# print(' '.join(map(str, a)))
# print(' '.join(map(str, partners)))

c = [1]
total_sum = sum(a)
coal_size = a[0]

for i, p in enumerate(partners):
    if 2 * coal_size > total_sum:
        break
    if a[0] >= 2 * p:
        c.append(i + 2)
        coal_size += p

if 2 * coal_size <= total_sum:
    c = []

print(len(c))
if len(c) > 0:
    print(' '.join(map(str, c)))
