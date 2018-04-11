/* Problem: https://leetcode.com/problems/add-two-numbers/

* Author: Aaron Zhang
* Date: 15. February 2016
*
* You are given two linked lists representing two non-negative numbers. 
* The digits are stored in reverse order and each of their nodes contain a single digit. 
* Add the two numbers and return it as a linked list.
*
* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output: 7 -> 0 -> 8
*
* Subscribe to see which companies asked this question
*
*
* Show Tags
*
* Linked List
* Math
*
*
*
* Show Similar Problems
*
*  (M) Multiply Strings
*  (E) Add Binary
*
*
*
*/

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    explicit ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *AddTwoNumbers(ListNode *first, ListNode *second) {
        int first_value, second_value, carry = 0, sum = 0;
        ListNode *head = NULL, **current = &head;

        while (first != NULL || second != NULL) {
            first_value = GetValueAndStepForward(first);
            second_value = GetValueAndStepForward(second);

            sum = carry + first_value + second_value;

            ListNode *node = new ListNode(sum % 10);
            *current = node;
            current = (&node->next);

            carry = sum / 10;
        }

        if (carry > 0) {
            ListNode *node = new ListNode(carry % 10);
            *current = node;
        }

        return head;
    }

private:
    int GetValueAndStepForward(ListNode* &node) {
        int value = 0;
        if (node != NULL) {
            value = node->val;
            node = node->next;
        }
        return value;
    }
};

int main() {
    return 1;
}
