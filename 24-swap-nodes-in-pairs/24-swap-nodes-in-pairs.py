# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        if not head or not head.next:
            return head
        
        dummy = ListNode(-1)
        dummy.next = head
        prev = dummy
        
        while prev.next and prev.next.next:
            current = prev.next
            forward = current.next
            temp = forward.next
            
            prev.next = forward
            forward.next = current
            current.next = temp
            
            prev = current
        
        return dummy.next
    