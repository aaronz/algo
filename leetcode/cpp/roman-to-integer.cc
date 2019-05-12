/* Problem: https://leetcode.com/problems/roman-to-integer/

* Author: Aaron Zhang
* Date: 15. February 2016
*
* Given a roman numeral, convert it to an integer.
* Input is guaranteed to be within the range from 1 to 3999.
*
* Subscribe to see which companies asked this question
*
*
* Show Tags
*
* Math
* String
*
*
*
* Show Similar Problems
*
*  (M) Integer to Roman
*
*
*
*/

#include <iostream>
#include <map>

using std::cout;
using std::endl;
using std::string;
using std::map;
using std::pair;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> lookup;
        lookup.insert(pair<char, int>('I', 1));
        lookup.insert(pair<char, int>('V', 5));
        lookup.insert(pair<char, int>('X', 10));
        lookup.insert(pair<char, int>('L', 50));
        lookup.insert(pair<char, int>('C', 100));
        lookup.insert(pair<char, int>('D', 500));
        lookup.insert(pair<char, int>('M', 1000));

        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i < s.size() - 1) {
                if (lookup[s[i]] < lookup[s[i + 1]])
                    sum -= lookup[s[i]];
                else
                    sum += lookup[s[i]];
            }
            else {
                sum += lookup[s[i]];
            }
        }
        return sum;
    }
};

void main() {
    Solution *s = new Solution();
    cout << s->romanToInt("IV") << endl;
    cout << s->romanToInt("LXXX") << endl;
}