# https://atcoder.jp/contests/abc249/tasks/abc249_b
# 6m
# AC! (flash!!)

import logging
from curses.ascii import isupper, islower

# logging.basicConfig(level=logging.DEBUG)

S = input()

ok = len(set(S)) == len(S)
ok &= any(map(isupper, S))
ok &= any(map(islower, S))

print("Yes" if ok else "No")
