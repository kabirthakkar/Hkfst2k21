from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:

        # get List from Linked List
        # .join the list
        # convert it to int and then add them
        # convert them back to ListNode

        lst1 = []
        lst2 = []

        def get_num(ln, lst):
            lst.append(ln.val)
            if ln.next:
                return get_num(ln.next, lst)
            else:
                string = ''
                for i in lst[::-1]:
                    string += str(i)
                return int(string)

        num1 = get_num(l1, lst1)
        num2 = get_num(l2, lst2)
        num = list(str(num1 + num2))
        Lnode = ListNode()

        def Get_Node(Lnode, num):
            if num:
                Lnode.val = num[0]
                if num[1:]:
                    Lnode.next = ListNode()
                    Get_Node(Lnode.next, num[1:])

        Get_Node(Lnode, num[::-1])
        print(Lnode)
        return Lnode
