# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        r= c = None
        carry = current = 0
        while l1 or l2:
            if not r:
                r = c = ListNode(0)
            current = 0
            if l1:
                current = current + l1.val
                l1 = l1.next
            if l2:
                current = current + l2.val
                l2 = l2.next
            current = current + carry
            carry = 1 if current > 9 else 0
            current = current % 10
            c.val = current
            if l1 or l2 or carry:
                c.next = ListNode(0)
                c = c.next
        if carry > 0:
            c.val = carry

        return r

left = ListNode(3)
left.next = ListNode(9)
right = ListNode(4)
right.next = ListNode(1)
result = Solution().addTwoNumbers(left, right)
while result:
    print(result.val)
    result = result.next