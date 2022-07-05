# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def findMid(self, curr):
        slow, fast = curr, curr
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        return slow
    
    def reverse(self, curr):
        prev = nxt = None
        
        while curr:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt
        return prev
    
    def reorderList(self, head: Optional[ListNode]) -> None:
        
        mid = self.findMid(head)
        t2 = mid.next
        mid.next = None
        
        t1 = head
        t2 = self.reverse(t2)
        
        dh = ListNode(-1) # dummy head
        dt = dh # dummy tail
        
        flag = True
        while t1 and t2:
            if flag:
                dt.next = t1
                t1 = t1.next
            else:
                dt.next = t2
                t2 = t2.next
            dt = dt.next
            flag = not flag
        
        if t1:
            dt.next = t1
        if t2:
            dt.next = t2
        
        head = dh.next
        