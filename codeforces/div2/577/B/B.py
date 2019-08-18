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
                k = j + 1
                while k < n and a[k] == a[j]:
                    k += 1
                d = min(a[j], a[i] // (k - j))
                a[i] -= d * (k - j)
                for l in range(j, k):
                    a[l] -= d

if s != 0:
    result = "NO"

print(result)
