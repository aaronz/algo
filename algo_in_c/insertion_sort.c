#include<stdio.h>

#define MAXLEN 100

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insert_sort(int array[], int length)
{
	int i, j;
	for (i = 1; i < length; i++){
		for (j = i; j > 0; j--){
			if (array[j] < array[j - 1]){
				swap(&array[j], &array[j - 1]);
			}
			else{
				break;
			}
		}
	}
}

int main()
{
	int array[MAXLEN];
	int length, i, input;

	i = 0;
	printf("enter numbers:\n");
	while (scanf("%d", &input) != EOF && i < MAXLEN){
		array[i] = input;
		i++;
	}
	length = i;
	insert_sort(array, length);
	printf("sorted result: ");
	for (i = 0; i < length; i++){
		printf("%d ", array[i]);
	}
}
