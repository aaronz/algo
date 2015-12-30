#ifndef _STACK_H
#define _STACK_H

typedef char stackElementT;

typedef struct{
	stackElementT *contents;
	int maxSize;
	int top;
} stackT;

void StackInit(stackT *stack, int maxSize);
void StackDestroy(stackT *stack);
void StackPush(stackT *stack, stackElementT element);
stackElementT StackTop(stackT *stack);
int StackIsEmpty(stackT *stack);
int StackIsFull(stackT *stack);

#endif