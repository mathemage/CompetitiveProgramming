#
# ?m
# ? AC! (flash!!)

import logging

# logging.basicConfig(level=logging.DEBUG)

N, A, B = map(int, input().split())

grid = [['?' * A*N for _ in range(B*N)]
color = '.'
for r in range(N):
    for c in range(N):
        for i in range(A):
            for j in range(B):
                grid[r*A + i][c*B + j] = color
        color = '.' if color == '#' else '.'

grid = '\n'.join(['?' * A*N for _ in range(B*N)])
print(grid)
