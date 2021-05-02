s = input()
factor = 0

total_ws = 0
consecutive_vs = 0
for c in s + 'o':
    if c == 'v':
        consecutive_vs += 1
    else:       # 'o'
        total_ws += max(0, consecutive_vs - 1)
        consecutive_vs = 0
# print(total_ws)

prefix_ws = 0
consecutive_vs = 0
for c in s:
    if c == 'v':
        consecutive_vs += 1
    else:       # 'o'
        prefix_ws += max(0, consecutive_vs - 1)
        consecutive_vs = 0
        factor += prefix_ws * (total_ws - prefix_ws)

print(factor)
