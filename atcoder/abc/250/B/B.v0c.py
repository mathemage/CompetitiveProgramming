#
# ?m
# ? AC! (flash!!)

import logging

logging.basicConfig(level=logging.DEBUG)

N, A, B = map(int, input().split())

grid = []
color = '.'
for r in range(N):
    for i in range(A):
        row = ""
        for c in range(N):
            for j in range(B):
                row += color
            logging.debug(f"<- color == {color}")
            color = '#' if color == '.' else '#'
            logging.debug(f"-> color == {color}")

        grid.append(row)
        color = '.' if color == '#' else '.'

grid = '\n'.join(grid)
print(grid)
