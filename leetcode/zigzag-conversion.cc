/* Problem: https://leetcode.com/problems/zigzag-conversion/

* Author: Aaron Zhang
* Date: 15. February 2016
* 
* 
* The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
* 
* P   A   H   N
* A P L S I I G
* Y   I   R
* 
* 
* And then read line by line: "PAHNAPLSIIGYIR"
* 
* Write the code that will take a string and make this conversion given a number of rows:
* 
* string convert(string text, int nRows);
* convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
* 
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
#include <string>

using namespace std;

string convert(string s, int numRows) {
	string result;
	if (numRows <= 1) return s;
	int columnItemCount = 2 * numRows - 2;
	int index, columnCount = (s.size() + 1) / columnItemCount;
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j <= columnCount; j++) {
			index = i + columnItemCount * j;
			if (index < s.size()) {
				cout << index << endl;
				result.push_back(s[index]);
			}
			if (i > 0 && i < numRows - 1) {
				index = columnItemCount - i + (columnItemCount * j);
				if (index < s.size()) {
					cout << index << endl;
					result.push_back(s[index]);
				}
			}
		}
	}
	return result;
}

void main() {
	string s("PAYPALISHIRING");
	string r = convert(s, 1);
	cout << r << endl;
}