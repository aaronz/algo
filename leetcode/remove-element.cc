/* Problem: https://leetcode.com/problems/remove-element/

* Author: Aaron Zhang
* Date: 15. February 2016
*
* Given an array and a value, remove all instances of that value in place and return the new length.

*
*

* The order of elements can be changed. It doesn't matter what you leave beyond the new length.

*
*
* Subscribe to see which companies asked this question
*
*
* Show Tags
*
* Array
* Two Pointers
*
*
*
* Show Similar Problems
*
*  (E) Remove Linked List Elements
*  (E) Move Zeroes
*
*
*
*/

#include <iostream>
#include <vector>
#include "debug.h"

using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int i = 0, j = nums.size() - 1;
		while (i <= j) {
			if (nums[i] == val) {
				while (nums[j] == val && j > i) {
					j--;
				}
				nums[i] = nums[j];
				j--;
			}
			i++;
		}
		return j + 1;
	}
};



void main() {
	int a[] = {3};
	vector<int> v (a, a + 1);
	Solution *s = new Solution();
	int len = s->removeElement(v, 3);
	print_vector(v, len);
}