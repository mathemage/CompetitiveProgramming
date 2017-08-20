#!/usr/bin/python3


def memoize(f):
    memo = {}

    def helper(t):
        if t not in memo:
            memo[t] = f(t)
        return memo[t]

    return helper


@memoize  # http://www.python-course.eu/python3_memoization.php
def get_triple_char_counts(t: int) -> int:
    if t < 3:  # no triple consecutive chars possible
        return 0
    result = 0
    result += get_triple_char_counts(t - 1)  # "a*"
    result += get_triple_char_counts(t - 2)  # "ba*"
    result += get_triple_char_counts(t - 3)  # "bba*"
    result += pow(2, t - 3)                  # "bbb*"
    return result
