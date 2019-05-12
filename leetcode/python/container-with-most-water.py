# https://leetcode.com/problems/container-with-most-water
# Given n non-negative integers a1, a2, ..., an,
# where each represents a point at coordinate (i, ai).
# n vertical lines are drawn such that the two endpoints
# of line i is at (i, ai) and (i, 0). Find two lines,
# which together with x-axis forms a container,
# such that the container contains the most water.

# Note: You may not slant the container and n is at least 2.


class Solution(object):

    def maxArea(self, height):
        left, right = 0, len(height) - 1
        maxArea = 0
        while left < right:
            maxArea = max(maxArea, (right - left) *
                          min(height[left], height[right]))
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        return maxArea

print Solution().maxArea([1, 2, 3, 4, 5, 6, 7, 8])
print Solution().maxArea([1, 2])
