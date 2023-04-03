# https://atcoder.jp/contests/abc251/tasks/abc251_a
# 2m
# AC! (flash!!)

import logging

# logging.basicConfig(level=logging.DEBUG)

S = input()
ans = S * (6 // len(S))
print(ans)
