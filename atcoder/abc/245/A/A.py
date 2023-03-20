# https://atcoder.jp/contests/abc245/tasks/abc245_a
# 7m
# AC! (flash!)

A, B, C, D = map(int, input().split())

ans = ""
if A != C:
    ans = "Takahashi" if A < C else "Aoki"
else:
    ans = "Takahashi" if B <= D else "Aoki"

print(ans)
