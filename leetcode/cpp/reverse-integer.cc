/* Problem: https://leetcode.com/problems/reverse-integer/

* Author: Aaron Zhang
* Date: 15. February 2016
*
* Reverse digits of an integer.
*
* Example1: x =  123, return  321
* Example2: x = -123, return -321

*
* click to show spoilers.
* Have you thought about this?
* Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
* If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
* Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
* For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*
* Update (2014-11-10):

* Test cases had been added to test the overflow behavior.

*
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
*  (E) String to Integer (atoi)
*
*
*
*/

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int reverse(int x) {
    int current, result = 0;
    bool nagtive = false;
    vector<int> s;

    if (x < 0) {
        nagtive = true;
        x = -x;
    }
    for (int i = 0; x >= 1 * pow(10, i); i++) {
        current = ((int)(x / pow(10, i))) % 10;
        s.push_back(current);
        cout << current << endl;
    }
    for (int j = 0; j < s.size(); j++) {
        cout << "j:" << j << endl;
        result += s[j] * pow(10, s.size() - j - 1);
    }
    result = nagtive ? -result : result;
    if ((!nagtive && result < 0) || (nagtive && result > 0) )
        return 0;
    return result;
}

void main() {
    int result = reverse(1534236469);
    cout << result << endl;
}