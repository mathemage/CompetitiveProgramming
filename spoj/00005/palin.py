#!/usr/bin/env python3
def next_palindrome(k):
	palin = list(k)
	n = len(k)
	mid = n // 2
	
	# case 1: forward right
	just_copy = False
	for i in range(mid, n):
		mirrored = n - 1 - i
		if k[i] < k[mirrored]:
			just_copy = True
		if just_copy:
			palin[i] = palin[mirrored]
	
	# case 2: backward left
	if not just_copy:
		i = (n - 1) // 2    # TODO debug here
		while i >= 0 and k[i] == '9':
			i -= 1
		if i >= 0:
			palin[i] = str(int(k[i]) + 1)
			for j in range(i + 1, mid + 1):
				palin[j] = '0'
			for j in range(mid + 1, n):
				mirrored = n - 1 - j
				palin[j] = palin[mirrored]
		else:
			# case 3: "99...9" -> "100..01"
			raise NotImplementedError
	
	return ''.join(palin)


if __name__ == '__main__':
	t = int(input())
	for _ in range(t):
		k = input()
		print(next_palindrome(k))
