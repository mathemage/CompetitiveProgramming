# https://atcoder.jp/contests/abc250/tasks/abc250_b
# 28m :-/
# AC! (flash!!)

import logging

# logging.basicConfig(level=logging.DEBUG)

N, A, B = map(int, input().split())

grid = []
for r in range(N):
    for i in range(A):
        color = ord('.') if r % 2 == 0 else ord('#')
        row = ""
        for c in range(N):
            for j in range(B):
                row += chr(color)
            logging.debug(f"<- color == {color}")
            color ^= (ord('#') ^ ord('.'))
            logging.debug(f"-> color == {color}")

        grid.append(row)

grid = '\n'.join(grid)
print(grid)
