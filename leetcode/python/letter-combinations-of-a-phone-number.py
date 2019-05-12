# https://leetcode.com/problems/letter-combinations-of-a-phone-number
# Given a digit string, return all possible letter combinations that the number could represent.
# A mapping of digit to letters (just like on the telephone buttons) is given below.
# Input:Digit string "23"
# Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
# Note:
# Although the above answer is in lexicographical order, your answer could be in any order you want.


class Solution(object):

    def letterCombination(self, digits):
        if '' == digits:
            return []
        key_map = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz'
        }
        result = ['']
        for digit in digits:
            t = []
            for r in result:
                for k in key_map[digit]:
                    t.append(r + k)
            result = t

        return result

print Solution().letterCombination('23')