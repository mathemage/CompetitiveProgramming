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

counts = [v for _, v in sorted(values.items())]

K_sum = sum(counts[:K])
max_K_sum = K_sum
for i in range(K, len(counts)):
    decr = counts[i-K]
    incr = counts[i]
    K_sum -= decr
    K_sum += incr
    max_K_sum = max(max_K_sum, K_sum)

print(n - max_K_sum)
