/* Problem: https://leetcode.com/problems/implement-strstr/

* Author: Aaron Zhang
* Date: 15. February 2016
*
*

* Implement strStr().

*
*

* Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

*
*
* Subscribe to see which companies asked this question
*
*
* Show Tags
*
* Two Pointers
* String
*
*
*
* Show Similar Problems
*
*  (H) Shortest Palindrome
*
*
*
*/

#include <iostream>
#include <vector>
#include "debug.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;


int KMP(string haystack, string needle) {
    vector<int> T(needle.size() + 1, -1);

    if (needle.size() == 0) {
        return 0;
    }
    print_vector(T, T.size());

    for (int i = 1; i <= needle.size(); i++) {
        int next_comp_pos = T[i - 1];
        cout << "reset ncp:" << next_comp_pos << endl;
        while (next_comp_pos != -1 && needle[next_comp_pos] != needle[i - 1]) {
            next_comp_pos = T[next_comp_pos];
        }
        T[i] = next_comp_pos + 1;
        cout << " next_comp_pos:" << next_comp_pos << " " << "t[i]:" << T[i] << endl;
    }
    cout << endl;
    print_vector(T, T.size());

    int sp = 0;
    int kp = 0;
    while (sp < haystack.size()) {
        while (kp != -1 && (kp == needle.size() || needle[kp] != haystack[sp]))
            kp = T[kp];
        kp++;
        sp++;
        if (kp == needle.size())
            return sp - needle.size();
    }

    return -1;
}

void main() {
    cout << KMP("abcd abcdabcdefg", "abababac") << endl;
}
