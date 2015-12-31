#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

const int MIN_PRIORITY_QUEUE_CAPACITY = 16;

priority_queue *priority_queue_create(const int capacity, int (*comparator)(const void*, const void*)){
	int i;
	priority_queue *pq = NULL;
	if(capacity < MIN_PRIORITY_QUEUE_CAPACITY){
		printf("\nBad priority queue parameter. Minimum priority queue capacity is %d\n", MIN_PRIORITY_QUEUE_CAPACITY);
		return NULL;
	}

	pq = (priority_queue *)malloc(sizeof(priority_queue));
	if(pq == NULL){
		printf("\nPriority queue memory allocation failed.\n");
		return NULL;
	}

	pq->comparator = comparator;
	pq->min_capacity = capacity;
	pq->capacity = capacity;
	pq->heap_size = 0;

	pq->heap_array = malloc(capacity * sizeof(void *));

	if(pq->heap_array == NULL){
		printf("Priority queue heap memory allocation failed.\n");
		free(pq);
		return NULL;
	}

	for(i = 0; i < capacity; i++){
		pq->heap_array[i] = NULL;
	}

	return pq;
}

static void swap(priority_queue *pq, const int key_a, const int key_b){
	void *temp = NULL;
	temp = pq->heap_array[key_a];
	pq->heap_array[key_a] = pq->heap_array[key_b];
	pq->heap_array[key_b] = temp;
}

static int greater(priority_queue *pq, const int key_a, const int key_b){
	return pq->comparator(pq->heap_array[key_a],pq->heap_array[key_b]);
}

static void sink(priority_queue *pq, int key){
	while(2 * key < pq->heap_size){
		int j = 2 * key;
		if(j < pq->heap_size && greater(pq, j, j+1)) j++;
		if(!greater(pq, key, j)) break;
		swap(pq, key, j);
		k = j;
	}
}

static void swim(priority_queue *pq, int key){
	while(key > 1 && great(pq, key/2, k)){
		swap(pq, key, key/2);
		key = key/2;
	}
}

static int ensure_capacity(priority_queue *pq, const int min_capacity){
	int old_capacity, new_capacity;
	void **new_heap_array;
	old_capacity = pq->capacity;
	if(min_capacity > old_capacity){
		new_capacity = (old_capacity * 3)/2 + 1;
		if(new_capacity < min_capacity)
			new_capacity = min_capacity;
		new_heap_array = (void **)realloc((void *)pq->heap_array, new_capacity * sizeof(void * ));

		if(new_heap_array == NULL)
			return false;

		pq->heap_array = new_heap_array;
		pq->capacity = new_capacity;
	}
	return TRUE;
}

int priority_queue_insert(priority_queue *pq, void *item){
	if(pq == NULL){
		printf("Priority queue is uninitilized. \n");
		return FALSE;
	}
	if(item == NULL){
		printf("Item pointer is NULL.\n");
		return FALSE;
	}

	if(ensure_capacity(pq, pq->heap_size + 2) == FALSE){
		printf("Priority queue out of memory.\n");
		return FALSE;
	}

	pq->heap_array[++pq->heap_size] = item;
	swim(pq, pq->heap_size);
	return TRUE;
}

void *priority_queue_peek(priority_queue *pq){
	if(pq == NULL){
		printf("Priority queue is uninitilized.\n");
		return NULL
	}

	if(pq->heap_size > 0)
		return pq->heap_array[1];
	return NULL;
}

void *priority_queue_poll(priority_queue *pq){
	if(pq == NULL){
		printf("Priority queue is uninitilized.\n");
		return NULL
	}

	if(pq->heap_size != 0){
		swap(pq, 1, pq->heap_size);
		sink(pq, 1);
		pq->heap_size--;
		return pq->heap_array[pq->heap_size + 1];
	}
	return NULL;
}

int priority_queue_is_empty(const priority_queue *pq){
	if(pq == NULL){
		printf("Priority queue is uninitialized.\n");
		return ERROR_VALUE;
	}

	if(pq->heap_size == 0)
		return TRUE;
	else
		return FALSE;
}

int priority_queue_size(const priority_queue *pq){
	int new_capacity;
	void **new_heap_array;

	if(pq == NULL){
		printf("Priority queue is uninitialized.\n");
		return ERROR_VALUE;
	}

	return pq->heap_size;
}

void priority_queue_free_data(priority_queue **pq, void (*free_function)(void *)){
	int i;
	for(i = 1; i <= (*pq)->heap_size; i++){
		free_function((*pq)->heap_array[i]);
	}
	(*pq)->heap_size = 0;
}

void priority_queue_free(priority_queue **pq){
	if(pq == NULL){
		printf("Priority queue is uninitialized.\n");
		return;
	}

	free((*pq)->heap_array);
	free((*pq));
	(*pq) = NULL;

	printf("OK\n");
}

void priority_queue_print(const priority_queue *pq, char* (*to_string)(void *)){
	int i;
	char *item_string;

	if(pq == NULL){
		printf("Priority queue is uninitialized.\n");
		return;
	}

	for(i = 1; i <= pq->heap_size; i++){
		item_string = to_string(pq->heap_array[i]);
		printf("%s", item_string);
		free(item_string);
	}
	printf("\n");
}



