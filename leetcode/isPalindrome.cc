#include <iostream>

using namespace std;

class Solution{
public:
	bool isPalindrome(int x){
		if(x<0||(x!=0&&x%10==0)) return false;
		int sum = 0;
		while(sum < x){
			sum = sum * 10 + x%10;
			x = x/10;
		}
		return (x == sum) || (x == (sum/10));
	}
};

void main(){
	Solution *s = new Solution();
	cout<<s->isPalindrome(12321)<<endl;
	cout<<s->isPalindrome(1232)<<endl;
}