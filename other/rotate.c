#include "stdio.h"

void reverse(char* array, int from, int to){
	while (from < to){
		char a = array[from];
		array[from++] = array[to];
		array[to--] = a;
	}
}

void rotate(char* array, int n, int m){
	m %= n;
	reverse(array, 0, m - 1);
	reverse(array, m, n - 1);
	reverse(array, 0, n - 1);
}

void main(){
	char* array = "abcdef";
	rotate(array, 6, 3);
	printf("%s", array);
}