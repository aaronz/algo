/* Problem: https://leetcode.com/problems/odd-even-linked-list/
* Author: Aaron Zhang
* Date: 15. February 2016
*
* Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
* You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
*
* Example:

* Given 1->2->3->4->5->NULL,

* return 1->3->5->2->4->NULL.

*
*
* Note:

* The relative order inside both the even and odd groups should remain as it was in the input.

* The first node is considered odd, the second node even and so on ...

*
* Credits:Special thanks to @aadarshjajodia for adding this problem and creating all test cases.
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
*/

#include <iostream>

using std::cout;
using std::endl;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* currentOdd = head, *currentEven = NULL, *evenHead = NULL;

        while (currentOdd != NULL) {
            if (currentEven != NULL) {
                currentEven->next = currentOdd->next;
                currentEven = currentEven->next;
            }
            else {
                currentEven = currentOdd->next;
                evenHead = currentEven;
            }

            if (currentEven == NULL) {
                currentOdd->next = evenHead;
                break;
            }

            currentOdd->next = currentEven->next;
            currentEven->next = NULL;

            if (currentOdd->next == NULL) {
                currentOdd->next = evenHead;
                break;
            }
            currentOdd = currentOdd->next;
        }
        return head;
    }
};

void printList(ListNode *l) {
    while (l != NULL) {
        cout << l->val << "->";
        l = l->next;
    }
    cout << endl;
}

void main() {

    ListNode *head = new ListNode(1), *current = head;
    for (int i = 2; i < 10; i++) {
        ListNode *c = new ListNode(i);
        current->next = c;
        current = current->next;
    }
    Solution *s = new Solution();
    printList(head);
    ListNode *l = s->oddEvenList(head);
    printList(l);
}
