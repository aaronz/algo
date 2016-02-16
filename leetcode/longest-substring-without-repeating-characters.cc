/* Problem: https://leetcode.com/problems/longest-substring-without-repeating-characters/

* Author: Aaron Zhang
* Date: 15. February 2016
*
* Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*
* Subscribe to see which companies asked this question
*
*
* Show Tags
*
* Hash Table
* Two Pointers
* String
*
*
*
* Show Similar Problems
*
*  (H) Longest Substring with At Most Two Distinct Characters
*
*
*
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    map<char, int> m;
    int maxLen = 0, lastPosition = -1;
    for (int i = 0; i < s.size(); i++) {
        if (m.find(s[i]) != m.end() && lastPosition < m[s[i]]) {
            lastPosition = m[s[i]];
        }
        if (i - lastPosition > maxLen) {
            maxLen = i - lastPosition;
        }
        m[s[i]] = i;
    }
    return maxLen;
}

void main() {
    cout << lengthOfLongestSubstring("abcabcd") << endl;
    cout << lengthOfLongestSubstring("aaaa") << endl;
}