n, k = map(int, input().split())
y = list(map(int, input().split()))

y.sort()
d = 5 - k
candidates = [x for x in y if x <= d]
print(len(candidates) // 3)
