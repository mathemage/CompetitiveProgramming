# https://atcoder.jp/contests/abc248/tasks/abc248_a
# 5m
# AC! (flash!!)

import logging

# logging.basicConfig(level=logging.DEBUG)

# S = list(map(int, input().split(sep='')))
S = input()
S = list(map(int, [*S]))
logging.debug(f"S: {S}")

result = sum(range(10)) - sum(S)
print(result)
