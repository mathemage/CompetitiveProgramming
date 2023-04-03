#
# ?m
# ? AC! (flash!!)

import logging

# logging.basicConfig(level=logging.DEBUG)

N, A, B = map(int, input().split())

# grid = [['?' * A*N for _ in range(B*N)]

grid = []
color = '.'
for r in range(N):
    for i in range(A):
        row = ""
        for c in range(N):
            for j in range(B):
                row += color
                # grid[r*A + i][c*B + j] = color
            color = '.' if color == '#' else '.'
        grid.append(row)
        color = '.' if color == '#' else '.'

# grid = '\n'.join(['?' * A*N for _ in range(B*N)])
grid = '\n'.join(grid)
print(grid)
