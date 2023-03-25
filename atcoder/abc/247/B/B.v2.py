# https://atcoder.jp/contests/abc247/tasks/abc247_b
# 14m + 4m +
# WA -> WA -> testcases ->

import logging

# logging.basicConfig(level=logging.DEBUG)

N = int(input())
names = set()
forbidden = set()

s = [None] * N
t = [None] * N
for i in range(N):
    s[i], t[i] = input().split()
    logging.debug(f"s[i] == {s[i]}")
    logging.debug(f"t[i] == {t[i]}")
    logging.debug(f"_" * 80)

    for w in [s[i], t[i]]:
        if w in names:
            forbidden.add(w)
        else:
            names.add(w)

ok = True
for i in range(N):
    if (s[i] in forbidden) and (t[i] in forbidden):
        ok = False
        break

print("Yes" if ok else "No")
