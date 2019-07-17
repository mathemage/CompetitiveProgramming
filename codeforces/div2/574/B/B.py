n, k = map(int, input().split())

current = 0
eaten = None
for i in range(1, n + 1):
    current += i
    if current == k + (n - i):
        eaten = n - i
        break

if eaten is not None:
    print(eaten)
else:
    raise ValueError("n == {}, k == {}, eaten == {}, current == {}".format(n, k, eaten, current))
