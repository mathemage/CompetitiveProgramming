# https://atcoder.jp/contests/abc246/tasks/abc246_b
# 6m
# AC!! (flash!)

import logging
import math

logging.basicConfig(level=logging.DEBUG)

A, B = map(int, input().split())

length = math.sqrt(A*A + B*B)
ansX = A / length
ansY = B / length

print(f"{ansX} {ansY}")
