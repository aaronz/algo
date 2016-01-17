#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution{
public:
	ListNode* oddEvenList(ListNode* head){
		ListNode* currentOdd = head, *currentEven = NULL, *evenHead = NULL;

		while(currentOdd != NULL){
			if(currentEven != NULL){
				currentEven->next = currentOdd->next;
				currentEven = currentEven->next;
			}
			else{
				currentEven = currentOdd->next;				
				evenHead = currentEven;
			}

			if(currentEven == NULL){
				currentOdd->next = evenHead;
				break;
			}

			currentOdd->next = currentEven->next;
			currentEven->next = NULL;

			if(currentOdd->next == NULL){
				currentOdd->next = evenHead;
				break;
			}
			currentOdd = currentOdd->next;
		}
		return head;
	}
};

void printList(ListNode *l){
	while(l != NULL){
		cout<<l->val<<"->";
		l = l->next;
	}
	cout<<endl;
}

void main(){

	ListNode *head = new ListNode(1), *current = head;
	for(int i = 2; i < 10; i++){
		ListNode *c = new ListNode(i);
		current->next = c;
		current = current->next;
	}
	Solution *s = new Solution();
	printList(head);
	ListNode *l = s->oddEvenList(head);
	printList(l);
}
