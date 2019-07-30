n, x, y = map(int, input().split())
a = list(map(int, input().split()))

for d, ad in enumerate(a):
    inf = ad + 1

    l = max(0, d - x)
    l_min = min(a[l:d]) if l < d else inf
    r = min(n - 1, d + y)
    r_min = min(a[d + 1: r + 1]) if d < r else inf

    if ad < min(l_min, r_min):
        print(d + 1)
        break
