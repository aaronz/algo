/* Problem: https://leetcode.com/problems/palindrome-number/

* Author: Aaron Zhang
* Date: 15. February 2016
*
* Determine whether an integer is a palindrome. Do this without extra space.
* click to show spoilers.
* Some hints:
* Could negative integers be palindromes? (ie, -1)
* If you are thinking of converting the integer to string, note the restriction of using extra space.
* You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
* There is a more generic way of solving this problem.
*
*
* Subscribe to see which companies asked this question
*
*
* Show Tags
*
* Math
*
*
*
* Show Similar Problems
*
*  (E) Palindrome Linked List
*
*
*
*/

#include <iostream>

using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0 || (x != 0 && x % 10 == 0)) return false;
		int sum = 0;
		while (sum < x) {
			sum = sum * 10 + x % 10;
			x = x / 10;
		}
		return (x == sum) || (x == (sum / 10));
	}
};

void main() {
	Solution *s = new Solution();
	cout << s->isPalindrome(12321) << endl;
	cout << s->isPalindrome(1232) << endl;
}