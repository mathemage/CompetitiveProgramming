n = int(input())
a = list(map(int, input().split()))
a_rev = list(reversed(a))

m = int(input())
b = list(map(int, input().split()))

cnt1, cnt2 = 0, 0
for bi in b:
    cnt1 += a.index(bi) + 1
    cnt2 += a_rev.index(bi) + 1

print("{} {}".format(cnt1, cnt2))
