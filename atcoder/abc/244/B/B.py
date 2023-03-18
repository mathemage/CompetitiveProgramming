# https://atcoder.jp/contests/abc244/tasks/abc244_b
# 9m
# AC! (flash!)

import logging
# logging.basicConfig(level=logging.DEBUG)

# ESWN
dx = [1,  0, -1, 0]
dy = [0, -1,  0, 1]

N = int(input())
T = input()
logging.debug(f"T == {T}")

x, y = 0, 0
due_index = 0

for c in T:
    if c == 'S':
        x += dx[due_index]
        y += dy[due_index]
    if c == 'R':
        due_index = (due_index + 1) % 4

print(f"{x} {y}")
