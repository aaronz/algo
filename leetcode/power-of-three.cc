/* Problem: https://leetcode.com/problems/power-of-three/

* Author: Aaron Zhang
* Date: 15. February 2016
*
*

*     Given an integer, write a function to determine if it is a power of three.

*
*
* Follow up:

*     Could you do it without using any loop / recursion?

*
* Credits:Special thanks to @dietpepsi for adding this problem and creating all test cases.
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
*  (E) Power of Two
*
*
*
*/

#include <iostream>

using std::cout;
using std::endl;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 1 || n == 3) return true;
        if (n < 3) return false;

        double x = n / 3.0;
        if (hasDecimal(x)) return false;

        while (x > 3.0) {
            x = x / 3.0;
            //cout<<x<<' ';
            if (hasDecimal(x)) return false;
        }
        return x == 3.0;
    }

    bool hasDecimal(double f) {
        double x = f - (int)f;
        //cout<<"has decimal:"<<x<<' '<<endl;
        return (x != 0);
    }

    bool isPowerOfThree2(int n) {
        if (n > 1)
            while (n % 3 == 0)
                n /= 3;
        return n == 1;
    }
};

void main() {
    Solution *s = new Solution();
    //cout<<s->isPowerOfThree(2)<<endl;
    cout << s->isPowerOfThree2(43046720) << endl;
    //cout<<s->isPowerOfThree(15)<<endl;
    //cout<<s->isPowerOfThree(81)<<endl;
}