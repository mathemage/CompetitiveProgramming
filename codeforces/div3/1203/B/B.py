q = int(input())
for _ in range(q):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()

    a2 = [a[i] for i in range(0, len(a), 2)]
    a3 = [a[i+1] for i in range(0, len(a), 2)]
    if a2 != a3:
        print("NO")
        continue
    a3.reverse()

    areas = [ai * aj for ai, aj in zip(a2, a3)]
    if areas == [areas[0]] * 2 * n:
        print("YES")
    else:
        print("NO")
