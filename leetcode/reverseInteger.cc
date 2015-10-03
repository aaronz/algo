#include <iostream>
#include <vector>

using namespace std;

int reverse(int x) {
	int current, result = 0;
	bool nagtive = false;	
	vector<int> s;

	if(x < 0){
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
	if((!nagtive && result < 0) || (nagtive && result > 0) )
		return 0;
	return result;
}

void main() {
	int result = reverse(1534236469);
	cout << result << endl;
}