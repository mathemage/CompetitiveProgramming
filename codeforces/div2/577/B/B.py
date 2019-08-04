n = int(input())
a = list(map(int, input().split()))

a.sort(reverse=True)
s = sum(a)

result = "YES"
for i in range(n - 1):
    if a[i] > s - a[i]:
        result = "NO"
        break
    else:
        s -= 2 * a[i]
        for j in range(i + 1, n):
            if a[i] == 0:
                break
            else:
                d = min(a[i], a[j])
                a[i] -= d
                a[j] -= d

if s != 0:
    result = "NO"

print(result)
