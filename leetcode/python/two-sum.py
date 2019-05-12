class Solution2(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        mapping = dict(zip(nums, range(len(nums))))
        for k, v in mapping.items():
            if target - k in mapping:
                return [v, mapping[target-k]]
        return []


class Solution(object):
    def twoSum(self, nums, target):
        mapping = {}
        for index, num in enumerate(nums):
            if (target - num) in mapping:
                return [mapping[target - num], index]
            mapping[num] = index
        return None


print(Solution().twoSum([1, 2, 3, 4], 6))
print(Solution().twoSum([1, 2, 2, 4], 6))
print(Solution().twoSum([1, 2, 3, 4], 1))
print(Solution().twoSum([1, 2, 2, 4], 4))
