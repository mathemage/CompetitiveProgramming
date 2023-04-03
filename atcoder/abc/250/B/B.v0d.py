#
# ?m
# ? AC! (flash!!)

import logging

# logging.basicConfig(level=logging.DEBUG)

N, A, B = map(int, input().split())

grid = []
color = ord('.')
for r in range(N):
    for i in range(A):
        row = ""
        for c in range(N):
            for j in range(B):
                row += chr(color)
            logging.debug(f"<- color == {color}")
            color ^= (ord('#') ^ ord('.'))
            logging.debug(f"-> color == {color}")

        grid.append(row)
    color ^= (ord('#') ^ ord('.'))

grid = '\n'.join(grid)
print(grid)
