n, m = map(int, input().split())
primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]

ni = primes.index(n) if n in primes else None
mi = primes.index(m) if m in primes else None
print("YES" if mi is not None and ni is not None and mi == ni + 1 else "NO")
