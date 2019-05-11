def switch(v: int, d: int):
    new_v = (v + d) % 2
    return new_v


def get_neighbors(r: int, c: int, size=3):
    neighbors = [(r, c)]
    if r > 0:
        neighbors.append((r - 1, c))
    if r < size - 1:
        neighbors.append((r + 1, c))
    if c > 0:
        neighbors.append((r, c - 1))
    if c < size - 1:
        neighbors.append((r, c + 1))
    return neighbors


grid = [[1 for _ in range(3)] for _ in range(3)]
counts = [[None for _ in range(3)] for _ in range(3)]

counts[0] = list(map(int, input().split()))
counts[1] = list(map(int, input().split()))
counts[2] = list(map(int, input().split()))

for r in range(3):
    for c in range(3):
        for (i, j) in get_neighbors(r, c):
            grid[i][j] = switch(grid[i][j], counts[r][c])

for r in range(3):
    print(''.join(map(str, grid[r])))
