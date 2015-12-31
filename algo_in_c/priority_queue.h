#ifndef _PRIORITY_QUEUE_H
#define _PRIORITY_QUEUE_H

typedef struct priority_queue{
	int (*comparator)(const void *, const void *);
	int min_capacity;
	int capacity;
	void **heap_array;
	int heap_size;
} priority_queue;

priority_queue *priority_queue_create(const int size, int (*comparator)(const void *, const void *));
int priority_queue_insert(priority_queue *pq, void *item);
void *priority_queue_peek(priority_queue *pq);
void *priority_queue_poll(priority_queue *pq);
int prioirty_queue_is_empty(const priority_queue *pq);
int priority_queue_size(const priority_queue *pq);
void priority_queue_free_data(priority_queue **pq, void (*free_function)(void *));
void priority_queue_free(priority_queue **pq);
void priority_queue_print(const priority_queue *pq, char * (*to_string)(void *));

#endif