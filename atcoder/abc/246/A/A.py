# https://atcoder.jp/contests/abc246/tasks/abc246_a
# 4m
# AC!! (flash!!!) - yes, nice smart trick

import logging
logging.basicConfig(level=logging.DEBUG)

x, y = 0, 0
for _ in range(3):
    xi, yi = map(int, input().split())
    x ^= xi
    y ^= yi

print(f"{x} {y}")
