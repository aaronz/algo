#include<stdio.h>

void swap(int array[], int x, int y)
{
	int temp = array[x];
	array[x] = array[y];
	array[y] = temp;
}

void print_array(int array[], int start, int end)
{
	int i;
	for(i = start; i<= end; i++)
		printf("%d ", array[i]);
	printf("\n");
}

void quick_sort(int array[], int start, int end)
{
	int i,m;
	if(start >= end)
		return; 
	for(i = start+1, m = start; i <= end; i++){
		if(array[start] > array[i]){
			swap(array, i, ++m);
		}
	}
	swap(array, start, m);
	quick_sort(array, start, m-1);
	quick_sort(array, m+1, end);
}

void main()
{
	int array[] = {4,3,2,1,5,0,7,8,9};
	quick_sort(array, 0, 8);
	print_array(array, 0, 8);
}
