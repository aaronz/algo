#include <iostream>
#include <algorithm>
#include <vector>

void myfunction(int i){
	std::cout<<' '<<i;
}

struct myclass{
	void operator()(int i){std::cout<<' '<<i;}
} myobject;

int main(){
	std::vector<int> myvector;
	myvector.push_back(10);
	myvector.push_back(20);
	myvector.push_back(30);

	std::cout<<"myvector contains:";
	for_each(myvector.begin(), myvector.end(), myfunction);
	std::cout<<'\n';

	std::cout<<"myvector contains:";
	for_each(myvector.begin(), myvector.end(), myobject);
	std::cout<<'\n';

	return 0;
}