/* Problem: https://leetcode.com/problems/two-sum/

* Author: Aaron Zhang
* Date: 15. February 2016
*
* Given an array of integers, return indices of the two numbers such that they add up to a specific target.
* You may assume that each input would have exactly one solution.
*
* Example:
*

* Given nums = [2, 7, 11, 15], target = 9,

*

* Because nums[0] + nums[1] = 2 + 7 = 9,

* return [0, 1].

*
*
* UPDATE (2016/2/13):

* The return format had been changed to zero-based indices. Please read the above updated description carefully.

*
*
* Subscribe to see which companies asked this question
*
*
* Show Tags
*
* Array
* Hash Table
*
*
*
* Show Similar Problems
*
*  (M) 3Sum
*  (M) 4Sum
*  (M) Two Sum II - Input array is sorted
*  (E) Two Sum III - Data structure design
*
*
*
*/

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		unordered_map<int, int> m;
		vector<int> result;
		for (int i = 0; i < numbers.size(); i++) {
			if (m.find(numbers[i]) == m.end()) {
				m[target - numbers[i]] = i;
			}
			else {
				result.push_back(m[numbers[i]] + 1);
				result.push_back(i + 1);
				break;
			}
		}
		return result;
	}
}