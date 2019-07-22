n, k = map(int, input().split())
a = list(map(int, input().split()))

dp = [[None for _ in range(k)] for _ in range(n)]
for i in range(n):
    dp[i][0] = a[i] - a[0]
    for j in range(1, min(i + 1, k)):
        dp[i][j] = dp[i-1][j-1]
        back = i - 2
        while j - 1 <= back:
            # noinspection PyTypeChecker
            dp[i][j] = min(dp[i][j], dp[back][j-1] + a[i] - a[back+1])
            if a[i] - a[back+1] >= dp[i][j]:
                break
            back -= 1

print(dp[n-1][k-1])
