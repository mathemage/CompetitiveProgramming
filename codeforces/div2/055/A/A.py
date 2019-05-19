s = input()

lowers = 0
for c in s:
    lowers += int(c.islower())

print(s.upper() if 2 * lowers < len(s) else s.lower())
