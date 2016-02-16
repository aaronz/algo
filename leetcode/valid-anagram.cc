/* Problem: https://leetcode.com/problems/valid-anagram/

* Author: Aaron Zhang
* Date: 15. February 2016
*
* Given two strings s and t, write a function to determine if t is an anagram of s.
* For example,
* s = "anagram", t = "nagaram", return true.
* s = "rat", t = "car", return false.

*
* Note:

* You may assume the string contains only lowercase alphabets.
* Follow up:

* What if the inputs contain unicode characters? How would you adapt your solution to such case?
*
* Subscribe to see which companies asked this question
*
*
* Show Tags
*
* Hash Table
* Sort
*
*
*
* Show Similar Problems
*
*  (M) Group Anagrams
*  (E) Palindrome Permutation
*
*
*
*/
#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int a[26] = {};
        for (int i = 0; i < s.length(); i++) {
            a[s[i] - 'a']++;
        }

        for (int i = 0; i < t.length(); i++) {
            a[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (a[i] != 0)
                return false;
        }
        return true;
    }
};

int main() {
    return 1;
}