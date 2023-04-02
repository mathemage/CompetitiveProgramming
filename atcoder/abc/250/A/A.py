# https://atcoder.jp/contests/abc250/tasks/abc250_a
# 9m
# AC! (flash!!)

import logging

# logging.basicConfig(level=logging.DEBUG)

H, W = map(int, input().split())
R, C = map(int, input().split())

ans = 0
for (dr, dc) in [(0, -1), (0, 1), (-1, 0), (1, 0)]:
    logging.debug(f"(dr, dc) == {(dr, dc)}")
    if 1 <= R+dr <= H and 1 <= C+dc <= W:
        ans += 1
print(ans)
