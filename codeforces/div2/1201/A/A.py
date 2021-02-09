n, m = map(int, input().split())
c2ix = {'A': 0, 'B': 1, 'C': 2, 'D': 3, 'E': 4}
counts = [[0 for _ in range(5)] for _ in range(m)]
for _ in range(n):
    s = input()
    for i, c in enumerate(s):
        counts[i][c2ix[c]] += 1

a = list(map(int, input().split()))
result = 0
for i, ai in enumerate(a):
    result += ai * max(counts[i])

print(result)
