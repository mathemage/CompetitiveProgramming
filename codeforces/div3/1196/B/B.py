q = int(input())

for _ in range(q):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    r = []

    odds_in_last_segment = 0
    for i, x in enumerate(a):
        if x % 2 == 1:  # odd
            if len(r) < k:
                r.append(i + 1)

            if len(r) == k:
                r[-1] = i + 1
                odds_in_last_segment += 1

    if len(r) == k and odds_in_last_segment % 2 == 1:
        r[-1] = n
        print("YES")
        print(' '.join(map(str, r)))
    else:
        print("NO")
