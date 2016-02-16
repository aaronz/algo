/* Problem: https://leetcode.com/problems/longest-palindromic-substring/

* Author: Aaron Zhang
* Date: 15. February 2016
*
* Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
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
* Show Similar Problems
*
*  (H) Shortest Palindrome
*  (E) Palindrome Permutation
*
*
*
*/

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Solution {
public:

    string expandAroundCenter(string s, int c1, int c2) {
        int l = c1, r = c2;
        int n = s.length();
        while (l >= 0 && r <= n - 1 && s[l] == s[r]) {
            l--;
            r++;
        }
        if (r)
            return s.substr(l + 1, r - l - 1);
    }
    
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return "";

        string longest = s.substr(0, 1);
        for (int i = 0; i < n - 1; i++) {
            string p1 = expandAroundCenter(s, i, i);
            if (p1.length() > longest.length())
                longest = p1;
            string p2 = expandAroundCenter(s, i, i + 1);
            if (p2.length() > longest.length())
                longest = p2;
        }
        return longest;
    }
};

void main() {
    Solution *s = new Solution();
    cout << s->longestPalindrome("abcdcbf") << endl;
}