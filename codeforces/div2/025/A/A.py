n = int(input())
ns = list(map(int, input().split()))

xs = [k for k in ns if k % 2 == 0]
ys = [k for k in ns if k % 2 != 0]
zs = xs if len(xs) == 1 else ys
print(zs[0])
