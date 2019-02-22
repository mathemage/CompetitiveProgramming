n = int(input())
ns = list(map(int, input().split()))

xs = [i for i, k in enumerate(ns) if k % 2 == 0]
ys = [i for i, k in enumerate(ns) if k % 2 != 0]
zs = xs if len(xs) == 1 else ys
print(zs[0] + 1)
