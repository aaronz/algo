#include "queue.h"

#define MinQueueSize (5)

struct QueueRecord{
	int capacity;
	int front;
	int rear;
	int size;
	ElementType *array;
};

int IsEmpty(Queue q){
	return Q->size == 0;
}

void MakeEmpty(Queue q){
	Q->size = 0;
	Q->front = 1;
	Q->rear = 0;
}

static int Succ(int value, Queue q){
	if(++value==q->capacity)
		value = 0;
	return value;
}

void Enqueue(ElementType x, Queue q){
	if(IsFull(q))
		Error("Full queue");
	else{
		q->size++;
		q->rear = succ(q->rear, q);
		q->array[q->rear] = x;
	}
}