from unittest import TestCase
from amazon.triple_char.triple_char import get_triple_char_counts


class TestGetTripleCharCounts(TestCase):
    def test_get_triple_char_count(self, t, count):
        triple_char_count = get_triple_char_counts(t)
        try:
            assert count == triple_char_count
        except AssertionError:
            self.fail("get_triple_char_counts({}) == {}, but {} expected!"
                      .format(t, triple_char_count, count))

    def test00(self):
        self.test_get_triple_char_count(0, 0)

    def test01(self):
        self.test_get_triple_char_count(1, 0)

    def test02(self):
        self.test_get_triple_char_count(2, 0)

    def test03(self):
        self.test_get_triple_char_count(3, 1)

    def test04(self):
        self.test_get_triple_char_count(4, 3)

    def test05(self):
        self.test_get_triple_char_count(5, 8)

    def test06(self):
        self.test_get_triple_char_count(6, 20)

    def test07(self):
        self.test_get_triple_char_count(7, 48)

    def test08(self):
        self.test_get_triple_char_count(8, 112)

    def test09(self):
        self.test_get_triple_char_count(9, 256)

    def test10(self):
        self.test_get_triple_char_count(10, 576)
