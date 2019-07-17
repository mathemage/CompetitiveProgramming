n = int(input())
h = [None] * 2
h[0] = list(map(int, input().split()))
h[1] = list(map(int, input().split()))

top_max = h[0][0]
bot_max = h[1][0]

for col in range(1, n):
    new_top_max = max(top_max, bot_max + h[0][col])
    new_bot_max = max(bot_max, top_max + h[1][col])
    top_max = new_top_max
    bot_max = new_bot_max

total_max = max(top_max, bot_max)
print(total_max)
