T = int(input())

for _ in range(T):
    n = int(input())
    a = list(map(int, input().split()))

    a.sort()
    # print(a)

    k = 0
    if len(a) >= 3:
        base1 = a[-1]
        base2 = a[-2]
        left_steps = n - 2
        k = min(base2 - 1, left_steps)
    print(k)
