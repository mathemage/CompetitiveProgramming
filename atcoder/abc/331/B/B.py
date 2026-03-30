# https://atcoder.jp/contests/abc331/tasks/abc331_b
# ?m
# WA

import logging
import math

logging.basicConfig(format="> %(message)s", level=logging.DEBUG)

N, S, M, L = map(int, input().split())

sizes = [6, 8, 12]

cost = math.inf
prices = [S, M, L]
for size, price in zip(sizes, prices):
    logging.debug(f"size == {size}")
    logging.debug(f"price == {price}")

    amount = (N + size - 1) // size
    logging.debug(f"amount == {amount}")

    cost = min(cost, price * amount)
    logging.debug(f"cost == {cost}")
    logging.debug(f"__________")

print(cost)
