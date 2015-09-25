#include <stdio.h>
#include <time.h>

#include "binary_search_tree.h"

using namespace ds;

int main(){
    const int kMaxElement = 10;
    int key[kMaxElement];
    int value[kMaxElement];

	BinarySearchTree<int, int> t;

    int i = 0;
    srand(time(NULL));
    for (i = 0; i < kMaxElement; i++){
        key[i] = rand() % 100;
        value[i] = rand() % 1000;
    }

    for (i = 0; i < kMaxElement; i++){
        printf("insert %d->%d\n", key[i], value[i]);
        t.Insert(key[i], value[i]);
    }

    t.Traverse();

    for (i = 0; i < kMaxElement; i++){
        printf("getting %d->%d\n", key[i], t.Find(key[i])->value);
    }

    for (i = 0; i < kMaxElement; i++){
        t.Delete(key[i]);
		t.Traverse();
        printf("deleted %d\n\n", key[i]);
    }

    return 0;
}