#include <iostream>

using namespace std;

class Solution{
public:
	bool canWinNim(int n){
		return n%4!=0;
	}
};

void main(){
	Solution *s = new Solution();
	cout<<s->canWinNim(4)<<endl;
	cout<<s->canWinNim(5)<<endl;
}