guest = input()
host = input()
pile = input()

print("YES" if sorted(pile) == sorted(guest + host) else "NO")
