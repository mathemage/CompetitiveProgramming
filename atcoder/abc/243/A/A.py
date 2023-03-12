# https://atcoder.jp/contests/abc243/tasks/abc243_a
# 5m
# AC! (flash)

import logging
logging.basicConfig(level=logging.DEBUG)

V, A, B, C = map(int, input().split())

V %= A+B+C

if V < A:
    print("F")
elif V < A+B:
    print("M")
else:
    print("T")
