/* Problem: https://leetcode.com/problems/longest-common-prefix/

* Author: Aaron Zhang
* Date: 15. February 2016
*
* Write a function to find the longest common prefix string amongst an array of strings.

*
*
* Subscribe to see which companies asked this question
*
*
* Show Tags
*
* String
*
*
*
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string prefix = "";
		for (int idx = 0; strs.size() > 0; prefix += strs[0][idx], idx++)
			for (int i = 0; i < strs.size(); i++)
				if (idx >= strs[i].size() || (i > 0 && strs[i][idx] != strs[i - 1][idx]))
					return prefix;
		return prefix;
	}
};

void main() {
	vector<string> v;
	v.push_back("flower");
	v.push_back("flow");
	v.push_back("flight");
	Solution *s = new Solution();
	cout << s->longestCommonPrefix(v) << endl;
}