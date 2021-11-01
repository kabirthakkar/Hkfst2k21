# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        head = ListNode()
        temp = head
        carry = 0
        while l1 and l2:
            total = l1.val+l2.val+carry
            temp.next = ListNode(total%10)
            temp = temp.next
            l1 = l1.next
            l2 = l2.next
            carry = total//10
        if not l1:
            while l2:
                total = l2.val+carry
                temp.next = ListNode(total%10)
                temp = temp.next
                carry = (total)//10
                l2 = l2.next
                
        if not l2:
            while l1:
                total = l1.val+carry
                temp.next = ListNode(total%10)
                temp = temp.next
                carry = (l1.val+carry)//10
                l1 = l1.next
        if carry :
            temp.next = ListNode(carry)
            temp = temp.next
        return head.next
             
