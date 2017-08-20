#!/usr/bin/python3

from amazon.triple_char.test_get_triple_char_counts import TestGetTripleCharCounts
from amazon.triple_char.triple_char import get_triple_char_counts

if __name__ == '__main__':
    # TestGetTripleCharCounts.test00()
    # TestGetTripleCharCounts.test01()
    # TestGetTripleCharCounts.test02()
    # TestGetTripleCharCounts.test03()
    # TestGetTripleCharCounts.test04()
    # TestGetTripleCharCounts.test05()
    # TestGetTripleCharCounts.test06()
    # TestGetTripleCharCounts.test07()
    # TestGetTripleCharCounts.test08()
    # TestGetTripleCharCounts.test09()
    # TestGetTripleCharCounts.test10()
    for t in range(10):
        print("{} -> {}".format(t, get_triple_char_counts(t)))
