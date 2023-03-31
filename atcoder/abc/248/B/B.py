# https://atcoder.jp/contests/abc248/tasks/abc248_b
# ?m (<3-4m)
# AC! (flash)

import logging

logging.basicConfig(level=logging.DEBUG)

A, B, K = map(int, input().split())

ans = 0
while A < B:
    A *= K
    ans += 1
print(ans)
