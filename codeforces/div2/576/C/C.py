n, I = map(int, input().split())
a = list(map(int, input().split()))

k = (8 * I) // n
K = 1
for _ in range(k):
    K *= 2
    if K > n:
        K = n
        break

values = {}
for ai in a:
    if ai not in values.keys():
        values[ai] = 0
    values[ai] += 1

sorted_values = sorted(values.items(), key=lambda kv: kv[1], reverse=True)
print(n - sum([v for _, v in sorted_values[:K]]))
