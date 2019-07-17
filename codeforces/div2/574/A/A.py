n, k = map(int, input().split())

counts = [0] * k
for _ in range(n):
    counts[int(input()) - 1] += 1

result = 0
odds = 0
for c in counts:
    result += 2 * (c // 2)
    odds += c % 2
result += (odds + 1) // 2

print(result)
