class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        for i in xrange(len(nums)):
            if(nums[i] >= target):
                return i
            else:
                i = i + 1
        return i

print Solution().searchInsert([0,1,2,6,8],5)
print Solution().searchInsert([0,1,2,6,8],8)
print Solution().searchInsert([0,1,2,6,8],9)