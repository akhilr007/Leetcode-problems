"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if(head is None):
            return None
        
        curr = head
        while curr:
            dummy = Node(curr.val)
            nxt = curr.next
            curr.next = dummy
            dummy.next = nxt
            curr = nxt
        
        curr = head
        while curr:
            if curr.random:
                curr.next.random = curr.random.next
            else:
                curr.next.random = None
            curr = curr.next.next
        
        c1 = head
        c2 = head.next
        
        result = head.next
        
        while c1 and c2:
            n1 = c2.next
            n2 = None
            if n1:
                n2 = n1.next
            
            c1.next = n1
            c2.next = n2
            
            c1 = n1
            c2 = n1
            
        return result