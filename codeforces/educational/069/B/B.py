n = int(input())
a = list(map(int, input().split()))

current = n
left = right = a.index(current)
answer = True
while left >= 0 and right <= n - 1 and current > 1:
    current -= 1
    if left - 1 >= 0 and a[left - 1] == current:
        left -= 1
        continue
    elif right + 1 <= n - 1 and a[right + 1] == current:
        right += 1
        continue
    else:
        answer = False
        break

print("YES" if answer else "NO")
