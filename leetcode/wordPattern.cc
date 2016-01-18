#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

class Solution{
public:
	bool wordPattern(string pattern, string str){
		map<char, string> m;
		map<string, char> n;
		istringstream in(str);
		int i = 0;
		for(string word; in >> word; i++){
			cout<<i<<"->"<<pattern[i]<<"->"<<word<<endl;
			if(i >= pattern.size())
				return false;

			if(n.find(word)==n.end()){
				n.insert(pair<string, char>(word, pattern[i]));
			}
			else{
				if(n[word] != pattern[i]){
					return false;
				}
			}

			if(m.find(pattern[i]) == m.end()){
				m.insert(pair<char, string>(pattern[i], word));
			}
			else{
				if(m[pattern[i]] != word){
					return false;
				}
			}
		}
		if(i != pattern.size()){
			cout<<i<<endl;
			return false;
		}
		return true;
	}
};

void printMap(map<char, string> m){
	map<char, string>::iterator it;
    for(it = m.begin(); it!= m.end(); ++it){
    	cout<<it->first<<"=>"<<it->second<<endl;
    }
}

void main(){
	//map<char, string> m;
	//m.insert(pair<char, string>('a',"cat"));
	//m.insert(pair<char, string>('b', "baby"));
	//printMap(m);
	Solution *s = new Solution();
	cout<<s->wordPattern("abba", "dog cat cat dog")<<endl;
}