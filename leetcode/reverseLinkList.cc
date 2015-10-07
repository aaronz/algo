#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

void printList(ListNode *l) {
    while (l != NULL) {
        cout << l->val << "->";
        l = l->next;
    }
    cout << endl;
}

ListNode* reverseList(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *current = head->next, *next;
    head->next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = head;
        head = current;
        if (next != NULL)
            current = next;
        else
            break;
    }
    return head;
}

void main() {
    ListNode *a = new ListNode(10);
    ListNode *t = a;
    for (int i = 0; i < 10; i++) {
        t->next = new ListNode(t->val + i);
        t = t->next;
    }
    printList(a);
    ListNode *result = reverseList(a);
    printList(result);
}