#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void StackInit(stackT *stack, int maxSize){
	stackElementT *newContents;
	newContents = (stackElementT *)malloc(sizeof(maxSize));
	if(newContents == NULL){
		fprintf(stderr, "Insufficient memory to initialize stack.\n");
		exit(1);
	}

	stack->contents = newContents;
	stack->maxSize = maxSize;
	stack->top = -1;
}

void StackDestroy(stackT *stack){
	free(stack->contents);

	stack->contents = NULL;
	stack->maxSize = 0;
	stack->top = -1;
}

void StackPush(stackT *stack, stackElementT element){
	if(StackIsFull(stack)){
		fprintf(stderr, "Can't push element on stack: stack is full.\n");
		exit(1);
	}

	stack->contents[++stack->top] = element;
}

stackElementT StackPop(stackT *stack){
	if(StackIsEmpty(stack)){
		fprintf(stderr, "Can't pop element from stack: stack is empty.\n");
		exit(1);
	}

	return stack->contents[stack->top--];
}

int StackIsEmpty(stackT *stack){
	return stack->top < 0;
}

int StackIsFull(stackT *stack){
	return stack->top >= stack->maxSize - 1;
}

