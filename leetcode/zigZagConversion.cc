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