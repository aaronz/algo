/* Problem: https://leetcode.com/problems/word-pattern/

* Author: Aaron Zhang
* Date: 15. February 2016
* 
* Given a pattern and a string str, find if str follows the same pattern.
*  Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
* 
* Examples:
* 
* pattern = "abba", str = "dog cat cat dog" should return true.
* pattern = "abba", str = "dog cat cat fish" should return false.
* pattern = "aaaa", str = "dog cat cat dog" should return false.
* pattern = "abba", str = "dog dog dog dog" should return false.
* 
* 
* Notes:
* You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
* 
* Credits:Special thanks to @minglotus6 for adding this problem and creating all test cases.
* 
* Subscribe to see which companies asked this question
* 
* 
* Show Tags
* 
* Hash Table
* 
* 
* 
* Show Similar Problems
* 
*  (E) Isomorphic Strings
*  (H) Word Pattern II
* 
* 
* 
*/

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