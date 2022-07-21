# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        
        def reverse(curr):
            prev, nxt = None, None
            while curr:
                nxt = curr.next
                curr.next = prev
                
                prev = curr
                curr = nxt
            return prev
        
        
        curr, prev = head, None
        count = 1
        
        while count != left:
            prev = curr
            curr = curr.next
            count += 1
        
        start = curr
        while count != right:
            curr = curr.next
            count += 1
            
        tail = curr.next
        curr.next = None
        
        newhead = reverse(start)
        
        if prev:
            prev.next = newhead
        
        curr = newhead
        while curr.next:
            curr = curr.next
        
        curr.next = tail
        
        if left==1:
            return newhead
        return head
    