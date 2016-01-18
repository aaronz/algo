#include <iostream>
#include <algorithm>
#include <vector>

bool myfunction(int i, int j){return i<j;}

struct myclass{
	bool operator()(int i, int j){return i<j;}
} myobject;

int main(){
	int myints[] = {32, 71, 12, 45, 26, 80, 53, 33};
	std::vector<int> myvector (myints, myints+8);

	std::sort(myvector.begin(), myvector.begin()+4);
	std::sort(myvector.begin()+4, myvector.end(), myfunction);
	std::sort(myvector.begin(), myvector.end(), myobject);

	std::cout<<"myvector contains";
	for(std::vector<int>::iterator it = myvector.begin(); it!=myvector.end(); it++)
		std::cout<<' '<<*it;
	std::cout<<'\n';
	return 0;
}