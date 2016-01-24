#include <iostream>
#include <vector>
#include "debug.h"

using namespace std;


int KMP(string haystack, string needle)
{
    vector<int> T(needle.size() + 1, -1);

    if(needle.size() == 0)
    {
        return 0;
    }

	for(int i = 1; i <= needle.size(); i++)
	{
		int pos = T[i - 1];
		while(pos != -1 && needle[pos] != needle[i - 1]) 
			pos = T[pos];
		T[i] = pos + 1;
	}
	print_vector(T, T.size());

	int sp = 0;
	int kp = 0;
	while(sp < haystack.size())
	{
		while(kp != -1 && (kp == needle.size() || needle[kp] != haystack[sp])) 
			kp = T[kp];
		kp++;
		sp++;
		if(kp == needle.size()) 
			return sp - needle.size();
	}
	
	return -1;
}

void main(){
	cout<<KMP("abcd abcdabcdefg","abcdab")<<endl;
}