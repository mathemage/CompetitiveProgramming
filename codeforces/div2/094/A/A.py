n = int(input())
a = list(map(int, input().split()))

parity = 0 if sum(a) % 2 == 0 else 1
print(len([x for x in a if x % 2 == parity]))
