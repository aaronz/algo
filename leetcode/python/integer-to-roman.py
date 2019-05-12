# https://leetcode.com/problems/integer-to-roman
# Given an integer, convert it to a roman numeral.
# Input is guaranteed to be within the range from 1 to 3999.


class Solution(object):

    def intToRoman(self, num):
        a = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"]
        b = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"]
        c = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"]
        d = ["", "M", "MM", "MMM"]
        return d[num / 1000] + c[(num % 1000) / 100] + b[(num % 100) / 10] + a[(num % 10)]

# test solution
print Solution().intToRoman(3540)
