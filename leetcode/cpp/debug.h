#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void print_vector(vector<int> v, int length){
    for(int i = 0; i < length; i++){
        cout<<v[i]<<' ';
    }
    cout<<endl;
}