#include <iostream>
#include <string>
#include <map>

using namespace std;

int lengthOfLongestSubstring(string s){
    map<char, int> m;
    int maxLen = 0, lastPosition = -1;
    for (int i = 0; i < s.size(); i++){
        if (m.find(s[i]) != m.end() && lastPosition < m[s[i]]){
            lastPosition = m[s[i]];
        }
        if (i - lastPosition > maxLen){
            maxLen = i - lastPosition;
        }
        m[s[i]] = i;
    }
    return maxLen;
}

void main(){
    cout << lengthOfLongestSubstring("abcabcd") << endl;
    cout << lengthOfLongestSubstring("aaaa") << endl;
}