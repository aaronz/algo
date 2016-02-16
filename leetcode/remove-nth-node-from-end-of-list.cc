/* Problem: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

* Author: Aaron Zhang
* Date: 15. February 2016
*
* Given a linked list, remove the nth node from the end of list and return its head.
*

* For example,
*

*    Given linked list: 1->2->3->4->5, and n = 2.

*

*    After removing the second node from the end, the linked list becomes 1->2->3->5.

*
*
* Note:

* Given n will always be valid.

* Try to do this in one pass.

*
*
* Subscribe to see which companies asked this question
*
*
* Show Tags
*
* Linked List
* Two Pointers
*
*
*
*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {};
};

void printList(ListNode * l) {
	while (l != NULL) {
		cout << l->val << "->";
		l = l->next;
	}
	cout << endl;
}

int length(ListNode* l) {
	int length = 0;
	while (l != NULL) {
		length++;
		l = l->next;
	}
	return length;
}

ListNode *remove(ListNode *head, int n) {
	if (head == NULL || head->next == NULL || n <= 0) return NULL;
	ListNode *first = head, *second;
	for (int i = 0; i < n; i++)
		first = first->next;
	second = head;
	while (first != NULL && first->next != NULL) {
		first = first->next;
		second = second->next;
	}
	//cout << "first:" << first->val << "second:" << second->val << endl;
	if (n == length(head)) {
		head = head->next;
	}
	else {
		second->next = second->next->next;
	}
	//cout << "second:" << second->val << endl;
	return head;
}

int main() {
	ListNode *t = new ListNode(10);
	ListNode *l = t;
	for (int i = 0; i < 1; i++) {
		l->next = new ListNode(i);
		l = l->next;
	}
	printList(t);
	ListNode * r = remove(t, 2);
	printList(r);
}