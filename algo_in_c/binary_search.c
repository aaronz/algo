#include "stdio.h"

int binary_search(int* a, int start, int end, int target){
	int m = (start + end)/2;
	if(start > end)
		return -1;
	if(a[m] == target)
		return m;
	else if(a[m] > target)
		return binary_search(a, start, m - 1, target);
	else
		return binary_search(a, m + 1, end, target);
}

int binary_search_no_recursive(int* a, int start, int end, int target){
	int m;
	while(start <= end){
		m = (start + end) / 2;
		if(a[m] == target)
			return m;
		else if(a[m] > target)
			end = m - 1;
		else
			start = m + 1;
	}
	return -1;
}

void main(){
	int a[] = {1,2,3,4,5,6,7};
	int index = binary_search(a, 0, 6, 5);
	printf("%d\n", index);
	index = binary_search_no_recursive(a, 0, 6, 5);
	printf("%d", index);
}