/* Problem: https://leetcode.com/problems/valid-parentheses/

* Author: Aaron Zhang
* Date: 15. February 2016
* 
* Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
* The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
* 
* Subscribe to see which companies asked this question
* 
* 
* Show Tags
* 
* Stack
* String
* 
* 
* 
* Show Similar Problems
* 
*  (M) Generate Parentheses
*  (H) Longest Valid Parentheses
*  (H) Remove Invalid Parentheses
* 
* 
* 
*/

#include <iostream>
#include <stack>

using namespace std;

class Solution{
public:
	bool isValid(string s){
		stack<char> st;
		for(int i = 0; i < s.size(); i++){
			if(st.empty() || (s[i] == '('||s[i]=='['||s[i]=='{'))
				st.push(s[i]);
			else if(s[i] == ')'||s[i]==']'||s[i]=='}'){
				char a = st.top();
				if((a == '(' && s[i] == ')') || (a == '[' && s[i] == ']') || (a == '{' && s[i] == '}'))
					st.pop();
				else
					return false;
			}
			else
				return false;
		}
		return st.empty();
	}
};

void main(){
	Solution *s = new Solution();
	cout<<s->isValid("(){}[]")<<endl;
	cout<<s->isValid("((){{}[]})")<<endl;
	cout<<int('{')<<' '<<int('}')<<endl;
	cout<<int('[')<<' '<<int(']')<<endl;
	cout<<int('(')<<' '<<int(')')<<endl;
}