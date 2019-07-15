n = int(input())

if n % 2 != 0:
    print(-1)
else:
    perm = []
    for i in range(n // 2):
        perm.append(2 * i + 2)
        perm.append(2 * i + 1)
    print(' '.join(map(str, perm)))
