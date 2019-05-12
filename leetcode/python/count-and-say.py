class Solution(object):
    def count_and_say(self, s):
        result = ''
        count = 1
        for i in xrange(1, len(s)+1):
            if i == len(s):
                result += str(count)
                result += s[i-1]
                count = 1
                continue

            if s[i-1] == s[i]:
                count += 1
            else:
                result += str(count)
                result += s[i-1]
                count = 1

        return result

    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        if n == 1:
            return '1'

        s = self.count_and_say('1')
        i = 1
        while i + 1 < n:
            s = self.count_and_say(s)
            i += 1
        return s



print Solution().countAndSay(1)
print Solution().countAndSay(2)
print Solution().countAndSay(3)
print Solution().countAndSay(4)
print Solution().countAndSay(5)
