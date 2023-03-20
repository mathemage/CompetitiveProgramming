# https://atcoder.jp/contests/abc245/tasks/abc245_b
# 6m
# AC! (flash!)

import logging
import math

# logging.basicConfig(level=logging.DEBUG)

N = int(input())
A = list(map(int, input().split()))
logging.debug(f"A: {A}")

for i in range(0, 2001):
    if i not in A:
        print(i)
        break
