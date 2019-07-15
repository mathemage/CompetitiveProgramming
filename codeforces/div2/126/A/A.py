n = int(input())
p = list(map(lambda x: float(x) / 100, input().split()))

print(100 * sum(p) / n)
