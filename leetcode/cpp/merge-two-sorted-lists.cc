/* Problem: https://leetcode.com/problems/merge-two-sorted-lists/

* Author: Aaron Zhang
* Date: 15. February 2016
*
* Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*
* Subscribe to see which companies asked this question
*
*
* Show Tags
*
* Linked List
*
*
*
* Show Similar Problems
*
*  (H) Merge k Sorted Lists
*  (E) Merge Sorted Array
*  (M) Sort List
*  (M) Shortest Word Distance II
*
*
*
*/

#include <iostream>

using std::cout;
using std::endl;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode *l) {
    while (l != NULL) {
        cout << l->val << "->";
        l = l->next;
    }
    cout << endl;
}

int getValueAndMoveNext(ListNode **l) {
    int result = 0;
    if (*l != NULL) {
        result = (*l)->val;
        *l = (*l)->next;
    }
    return result;
}

void compareAndMoveNext(ListNode **l1, ListNode **l2, ListNode **result) {
    if (*l1 == NULL && l2 != NULL) {
        *result = new ListNode(getValueAndMoveNext(l2));
    }
    else if (*l1 != NULL && *l2 == NULL) {
        *result = new ListNode(getValueAndMoveNext(l1));
    }
    else if (*l1 != NULL && *l2 != NULL) {
        if ((*l1)->val >= (*l2)->val) {
            *result = new ListNode(getValueAndMoveNext(l2));
        }
        else
        {
            *result = new ListNode(getValueAndMoveNext(l1));
        }
    }
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    ListNode *result, *t;
    compareAndMoveNext(&l1, &l2, &result);
    t = result;
    while (l1 != NULL || l2 != NULL) {
        compareAndMoveNext(&l1, &l2, &t->next);
        t = t->next;
    }
    return result;
}

void main() {
    ListNode *l1 = new ListNode(2);
    ListNode *l2 = new ListNode(1);

    ListNode *t1 = l1;
    ListNode *t2 = l2;

    for (int i = 0; i < 10; i++) {
        t1->next = new ListNode(t1->val + i);
        t2->next = new ListNode(t2->val + i);
        t1 = t1->next;
        t2 = t2->next;
    }
    printList(l1);
    printList(l2);

    ListNode *result = mergeTwoLists(l1, l2);
    printList(result);
}