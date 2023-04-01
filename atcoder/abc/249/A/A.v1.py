# https://atcoder.jp/contests/abc249/tasks/abc249_a
# 10m +
# WA :-/ -

import logging

# logging.basicConfig(level=logging.DEBUG)

A, B, C, D, E, F, X = map(int, input().split())


def get_distance(work, speed, rest):
    distance = 0
    time = 0
    while time < X:
        time += work
        distance += speed
        time += rest
    return distance


distance_Takahashi = get_distance(A, B, C)
distance_Aoki = get_distance(D, E, F)

ans = ""
if distance_Takahashi > distance_Aoki:
    ans = "Takahashi"
elif distance_Takahashi < distance_Aoki:
    ans = "Aoki"
else:
    ans = "Draw"
print(ans)
