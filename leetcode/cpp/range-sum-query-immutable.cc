#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class NumArray {
public:
    vector<int> v;

    NumArray(vector<int> &nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            v.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        if (i == 0) return v[j];
        return v[j] - v[i - 1];
    }
};


void main() {
    vector<int> vec;
    for (int i = 0; i < 10; i++) {
        vec.push_back(i);
    }
    NumArray *na = new NumArray(vec);
    cout << na->sumRange(0, 8) << endl;
}
