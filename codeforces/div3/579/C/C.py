from math import gcd, sqrt, ceil

n = int(input())
a = list(map(int, input().split()))

a = list(set(a))
divisor = a[0]
for ai in a[1:]:
    divisor = gcd(divisor, ai)

result = 1      # 1 is always a divisor
limit = ceil(sqrt(divisor)) + 1
primes = [2] + list(range(3, limit, 2))
for prime_factor in primes:
    power = 0
    while divisor % prime_factor == 0:
        divisor /= prime_factor
        power += 1
    if power > 0:
        result *= 1 + power

print(result)
