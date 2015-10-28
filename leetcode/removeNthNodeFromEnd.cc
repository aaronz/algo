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

int length(ListNode* l){
	int length = 0;
	while(l != NULL){
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