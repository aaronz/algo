#include<stdio.h>

// waste array[0] so that 
// left child = 2*i
// right child = 2*i+1


void print_heap(int array[], int length)
{
	int i = 0;
	while(i < length){
		printf("%d ", array[i]);
		i++;
	}
}

void swap(int array[], int x, int y)
{
	int temp = array[x];
	array[x] = array[y];
	array[y] = temp;
}

void sift_down(int array[], int length, int n)
{
	int left = 2*n;
	int right = 2*n+1;
	int max = n;
	if(left < length){
		if(array[n] < array[left])
			max = left;
	}
	if(right < length){
		if(array[max] < array[right])
			max = right;
	}
	if(max != n){
		swap(array, max, n);
		sift_down(array, length, max);
	}
}

void build_heap(int array[], int length)
{
	int i;
	for(i = length/2; i >= 1; i--){
		sift_down(array, length, i);
	}
}

void heap_sort(int array[], int length)
{
	int i = length;
	build_heap(array, length);
	while(i > 1){
		swap(array, 1, i-1);
		i--;
		sift_down(array, i, 1);
	}

}

void main()
{
	int array[] = {1,2,3,4,5,6,7,8,9};
	heap_sort(array, 9);
	print_heap(array, 9);

}

