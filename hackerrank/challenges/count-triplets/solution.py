import math
import os
import random
import re
import sys

# Complete the countTriplets function below.
def countTriplets(arr, r):
    count = 0

    # g3 = r * g2 = r^2 * g1
    g3s = {}
    g2s = {}

    for a in reversed(arr):
        a2 = a * r
#         print(f"a == {a}\t a2 == {a2}")
#         print(f"count_0 == {count}")

        # new triplet
        if a2 in g2s.keys():
            count += g2s[a2]

        # update g2s[a]
        if a2 in g3s.keys():
            if a not in g2s.keys():
                g2s[a] = 0
            g2s[a] += g3s[a2]

        # update g3s[a]
        if a not in g3s.keys():
            g3s[a] = 0
        g3s[a] += 1

#         print(f"g2s: {g2s}")
#         print(f"g3s: {g3s}")
#         print(f"count_1 == {count}")
#         print()

    del(g2s)
    del(g3s)
    return count

if __name__ == '__main__':
    nr = input().rstrip().split()

    n = int(nr[0])
    r = int(nr[1])
    arr = list(map(int, input().rstrip().split()))

    ans = countTriplets(arr, r)

    print(ans)
