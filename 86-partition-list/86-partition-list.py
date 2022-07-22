# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        
        if not head or not head.next:
            return head
        
        dh1 = ListNode(-1)
        dt1 = dh1
        
        dh2 = ListNode(-1)
        dt2 = dh2
        
        curr = head
        while curr:
            
            if curr.val < x:
                dt1.next = curr
                dt1 = dt1.next
            else:
                dt2.next = curr
                dt2 = dt2.next
            curr = curr.next
        
        dt2.next = None
        dt1.next = dh2.next
        return dh1.next
    