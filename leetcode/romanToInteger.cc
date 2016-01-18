#include <iostream>
#include <map>

using namespace std;

class Solution{
public:
	int romanToInt(string s){
		map<char, int> lookup;
		lookup.insert(pair<char,int>('I',1));
		lookup.insert(pair<char,int>('V',5));
		lookup.insert(pair<char,int>('X',10));
		lookup.insert(pair<char,int>('L',50));
		lookup.insert(pair<char,int>('C',100));
		lookup.insert(pair<char,int>('D',500));
		lookup.insert(pair<char,int>('M',1000));

		int sum = 0;
		for(int i = 0; i < s.size(); i++){
			if(i < s.size()-1){
				if(lookup[s[i]]<lookup[s[i+1]])
					sum -= lookup[s[i]];
				else
					sum += lookup[s[i]];
			}
			else{
				sum+=lookup[s[i]];
			}
		}
		return sum;
	}
};

void main(){
	Solution *s = new Solution();
	cout<<s->romanToInt("IV")<<endl;
	cout<<s->romanToInt("LXXX")<<endl;
}