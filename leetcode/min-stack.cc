/* Problem: https://leetcode.com/problems/min-stack/

* Author: Aaron Zhang
* Date: 15. February 2016
*
*

* Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

*
*

* push(x) -- Push element x onto stack.

*
*

* pop() -- Removes the element on top of the stack.

*
*

* top() -- Get the top element.

*
*

* getMin() -- Retrieve the minimum element in the stack.

*
*
*
* Subscribe to see which companies asked this question
*
*
* Show Tags
*
* Stack
* Design
*
*
*
* Show Similar Problems
*
*  (H) Sliding Window Maximum
*
*
*
*/

#include <iostream>

using namespace std;

struct StackNode {
	int val;
	int min;
	StackNode *next;
	StackNode(int x, int m): val(x), min(m), next(NULL) {};
};

class MinStack {
public:
	void push(int x) {
		int min = (list == NULL || list->min > x) ? x : list->min;
		StackNode *item = new StackNode(x, min);
		item->next = list;
		list = item;
	}

	void pop() {
		if (list != NULL)
			list = list->next;
	}

	int top() {
		return list == NULL ? 0 : list->val;
	}

	int getMin() {
		return list == NULL ? 0 : list->min;
	}

	bool isEmpty() {
		return list == NULL;
	}

private:
	StackNode *list = NULL;
};

void main() {
	MinStack *stack = new MinStack();
	for (int i = 10; i >= 0; i--) {
		stack->push(i);
		cout << stack->getMin() << endl;
	}

	while (!stack->isEmpty()) {
		int top = stack->top();
		stack->pop();
		cout << "pop" << top << "min" << stack->getMin() << endl;
	}
}