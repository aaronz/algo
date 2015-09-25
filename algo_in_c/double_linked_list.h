// http://en.wikipedia.org/wiki/Double_linked_list
// Copyright (c) 2015 Aaron Zhang
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef __DOUBLE_LINKED_LIST_H__
#define __DOUBLE_LINKED_LIST_H__

#include <stdlib.h>

struct ListHead{
	struct ListHead* next, * prev;
};

static inline void ListAdd(struct ListHead* n, struct ListHead* prev, struct ListHead* next){
	next->prev = n;
	n->prev = prev;
	n->next = next;
	prev->next = n;
}

static inline void ListDelete(struct ListHead* prev, struct ListHead* next){
	next->prev = prev;
	prev->next = next;
}

static inline void ListSplice(struct ListHead* list, struct ListHead* head){
	
}

// Insert a new entry after the specified head.
// @new: new entry to be added
// @head: list head to add it after
static inline void Add(struct ListHead* n, struct ListHead* head){
	ListAdd(n, head, head->next);
}

// Insert a new entry before the specified head.
// @new: new entry to be added
// @head: list head to add it before
static inline void AddTail(struct ListHead* n, struct ListHead *head){
	ListAdd(n, head->prev, head);
}

static inline void Delete(struct ListHead* entry){
	ListDelete(entry->prev, entry->next);
	entry->next = NULL;
	entry->prev = NULL;
}


#endif