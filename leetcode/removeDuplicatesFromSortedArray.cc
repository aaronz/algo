#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
	void moveForward(vector<int>& nums, int index){
		for(int i = index; i < nums.size()-1; i++)
			nums[i] = nums[i+1];
	}

	int removeDuplicates(vector<int>& nums){
		int removed = 0;
		for(int i = 0; i < nums.size()-removed; i++){
			int j = i+1;
			while(j < nums.size()-removed && nums[i]==nums[j]){
				moveForward(nums, j);
				removed++;
			}
		}
		return nums.size()-removed;
	}

	int removeDuplicates2(vector<int>& nums){
		if(nums.size() <= 1 ) return nums.size();
		int i = 1, j = 1, k = 0, removed = 0;
		while(j < nums.size()){
			if(nums[k] != nums[j]){
				nums[i] = nums[j];
				i++;
				k=j;
			}
			else{
				removed++;
			}
			j++;
		}
		return nums.size()-removed;
	}
};

void printVector(vector<int> nums, int length){
	for(int i = 0; i < length; i++){
		cout<<nums[i]<<"->";
	}
}

void main(){
	Solution *s = new Solution();
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);
	int length = s->removeDuplicates2(nums);
	printVector(nums, length);
}