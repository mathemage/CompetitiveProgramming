w, h = map(int, input().split())
prime = 998244353

n = 1
for _ in range(w + h):
    n *= 2
    n %= prime

print(n % prime)
