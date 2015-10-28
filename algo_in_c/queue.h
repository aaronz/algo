#ifndef _Queue_h

struct QueueRecord;
typedef struct QueueRecord *Queue;

int IsEmpty(Queue q);
int IsFull(Queue q);
Queue CreateQueue(int maxElements);
void DisposeQueue(Queue q);
void MakeEmpty(Queue q);
void Enqueue(ElementType x, Queue q);
ElementType Front(Queue q);
void Dequeue(Queue q);
ElementType FrontAndDequeue(Queue q);

#endif 

