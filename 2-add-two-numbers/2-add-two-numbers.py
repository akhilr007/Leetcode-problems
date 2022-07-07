# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        
        if l1 == None or l2 == None:
            return l1 if l1 != None else l2
        
        c1, c2 = l1, l2
        
        dh = ListNode(-1)
        dt = dh
        
        carry = 0
        
        while c1 or c2:
            v1 = c1.val if c1 else 0
            v2 = c2.val if c2 else 0
            
            sumVal = v1 + v2 + carry
            nodeValue = sumVal % 10
            carry = sumVal // 10
            
            nn = ListNode(nodeValue)
            dt.next = nn
            dt = dt.next
            
            if c1:
                c1 = c1.next
            if c2:
                c2 = c2.next
        
        if carry:
            nn = ListNode(1)
            dt.next = nn
            dt = dt.next
            dt.next = None
        
        return dh.next
    
            
        