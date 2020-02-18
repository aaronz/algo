class Solution:
    def find_next(self, s, t, start):
        i = start
        while i < len(s):
            if s[i] in t:
                return i
            else:
                i += 1
        return -1

    def minWindow(self, s, t):
        start = 0
        end = 0
        map = {}
        for i in range(len(s)):
            print("i:" + str(i))
            if s[i] in t:
                next = self.find_next(s, t, i+1)
                print("next:" + str(next))
                if next == -1:
                    if len(map) == len(t):
                        return s[start, i]
                    else:
                        return "" 
                else:
                    map[s[i]] = next
                
                end = i
                print("end:" + str(end))
                
                if s[i] in map:
                    start = map[s[i]]
                    print("start:" + str(start))

        if len(map) == len(t):
            return s[start:end]
        else:
            return ""


print(Solution().minWindow("abcdab", "ab"))
