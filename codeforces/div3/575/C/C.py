q = int(input())

for _ in range(q):
    n = int(input())

    x_min = -100000
    x_max = 100000
    y_min = -100000
    y_max = 100000
    possible = True
    for _ in range(n):
        x, y, f1, f2, f3, f4 = map(int, input().split())

        if f1 == 0:  # west
            x_min = max(x_min, x)
        if f2 == 0:  # north
            y_max = min(y_max, y)
        if f3 == 0:  # east
            x_max = min(x_max, x)
        if f4 == 0:  # south
            y_min = max(y_min, y)

    if x_min <= x_max and y_min <= y_max:
        print("1 {} {}".format(x_min, y_min))
    else:
        print("0")
