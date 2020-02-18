class Solution:
    def lengthOfLongestSubstring(self, s):
        map = {}
        last_position = 0
        max_length = 0
        for i in range(len(s)):
            if s[i] in map:
                last_position = max(map[s[i]], last_position)
            max_length = max(i - last_position + 1, max_length)
            map[s[i]] = i + 1
        return max_length

print(Solution().lengthOfLongestSubstring("abcabcd"))
            