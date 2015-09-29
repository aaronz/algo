#include "stdio.h"

void left_shift_one(char* array, int size){
	int i, temp = array[0];
	if (size < 2) return;
	for (i = 0; i < size - 1; i++){
		array[i] = array[i + 1];
	}
	array[size - 1] = temp;
}

void shift(char* array, int size, int n){
	int x = n % size;
	while (x > 0){
		left_shift_one(array, size);
		x--;
	}
	printf("%s", array);
}

int main(){
	char* array = "abcde";
	shift(array, 5, 7);
}