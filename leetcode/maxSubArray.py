class Solution(object):
    def maxSubArray(self, nums):
        i, current, max = 0, 0, nums[0]
        while i < len(nums):
            current += nums[i]
            i += 1            
            if current > max:
                max = current
            if current <= 0:
                current = 0
                continue
        return max