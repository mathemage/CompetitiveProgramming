n, k, l, c, d, p, nl, np = map(int, input().split())

drink = (k * l) // nl
limes = c * d
salt = p // np
result = min(drink, limes, salt) // n
print(result)
