n = int(input())
a = list(map(int, input().split()))

watermark = a[-1]   # reverse high-water mark as in https://www.investopedia.com/terms/h/highwatermark.asp
for i in reversed(range(n - 1)):
	if a[i] < watermark:
		watermark = a[i]
	else:
		a[i] = max(watermark - 1, 0)
		watermark = a[i]

print(sum(a))
