# https://atcoder.jp/contests/abc242/tasks/abc242_a
# 17m
# AC! (flash)
import logging

# logging.basicConfig(level=logging.DEBUG)

A, B, C, X = map(int, input().split())
logging.debug(
    f"A == {A}, "
    f"B == {B}, "
    f"C == {C}, "
    f"X == {X}"
)

ans = 0.
if X <= A:
    ans = 1.
    logging.debug(f"1) {X} <= {A}")
elif A + 1 <= X <= B:
    ans = C / (B - A)
    logging.debug(f"2) ")

print(ans)
