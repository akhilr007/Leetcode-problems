# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        if not head or not head.next:
            return head
        
        dh = ListNode(-1)
        dt = dh
        
        visit = set()
        
        c1, c2 = head, head.next
        while c1 and c2:
            if c1.val != c2.val and c1.val not in visit:
                dt.next = c1
                dt = dt.next
                visit.add(c1.val)
            else:
                visit.add(c1.val)
            c1 = c1.next
            c2 = c2.next
        
        if c1.val not in visit:
            dt.next = c1
            dt = dt.next
        
        dt.next = None
        return dh.next
    