def main():
	hist = {}
	for k, a_i in enumerate(a):
		if a_i not in hist:
			hist[a_i] = 0
		hist[a_i] += 1

		current_height = 0
		carryover = None
		for h_i, count in reversed(sorted(hist.items())):
			cnt = count
			if carryover:
				cnt -= 1

			current_height += h_i * (cnt // 2)
			if cnt % 2 != 0:
				current_height += h_i
				carryover = h_i
			else:
				carryover = None

			if current_height > h:
				return k
	return n


if __name__ == '__main__':
	n, h = map(int, input().split())
	a = list(map(int, input().split()))
	print(main())
