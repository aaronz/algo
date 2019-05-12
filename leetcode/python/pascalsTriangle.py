class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        result = []
        if numRows == 0:
            return result
        elif numRows == 1:
            result.append([1])
        else:
            result.append([1])
            i = len(result)
            while i < numRows:
                j = 1
                current = [1]
                while j < i:
                    current.append(result[i-1][j-1] + result[i-1][j])
                    j += 1
                current.append(result[i-1][len(result[i-1])-1])
                result.append(current)
                i = len(result)
        return result

print Solution().generate(1)
print Solution().generate(2)
print Solution().generate(3)
print Solution().generate(4)