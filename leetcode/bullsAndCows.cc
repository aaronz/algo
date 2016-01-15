#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
	string getHint(string secret, string guess){
		int a = 0, b = 0;
		int hash1[] = {0,0,0,0,0,0,0,0,0,0};
		for(int i = 0; i < secret.length(); i++){
			if(secret[i] == guess[i]) a++;
			hash1[secret[i]-'0']++;
			hash1[guess[i]-'0']--;
		}
		for(int i = 0; i < 10; i++){
			if(hash1[i]>=0)
				b+=hash1[i];
		}
		b = secret.length()-b-a;
		return to_string(a)+"A"+to_string(b)+"B";
	}
};

void main(){
	Solution *s = new Solution();
	cout<<s->getHint("1123","0111")<<endl;
	cout<<s->getHint("1807","7810")<<endl;
}