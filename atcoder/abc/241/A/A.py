# https://atcoder.jp/contests/abc241/tasks/abc241_a
import logging
# logging.basicConfig(level=logging.DEBUG)

a = list(map(int, input().split()))
logging.debug(f"a: {a}")

display = 0


def press():
    global display
    display = a[display]


for _ in range(3):
    press()

print(display)
