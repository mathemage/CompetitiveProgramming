q = int(input())
for _ in range(q):
    n = int(input())
    p = list(map(int, input().split()))

    result = None
    p2 = 2 * p
    for pivot in [1, n]:
        ipivot = p2.index(pivot)
        segment = p2[ipivot: ipivot + n]
        if pivot == 1 and segment == list(range(1, n + 1)):
            result = "YES"
            break
        if pivot == n and segment == list(reversed(range(1, n + 1))):
            result = "YES"
            break
        else:
            result = "NO"

    print(result)
