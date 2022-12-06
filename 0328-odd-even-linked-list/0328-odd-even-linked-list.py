# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        if head is None or head.next is None or head.next.next is None:
            return head
        
        oddH = ListNode(-1)
        oddT = oddH
        evenH = ListNode(-1)
        evenT = evenH
        
        cur = head
        flag = False
        while cur:
            if flag == True:
                evenT.next = cur
                evenT = evenT.next
            else:
                oddT.next = cur
                oddT = oddT.next
            cur = cur.next
            flag = not flag
        
        oddT.next, evenT.next = None, None
        oddT.next = evenH.next
        
        return oddH.next
    