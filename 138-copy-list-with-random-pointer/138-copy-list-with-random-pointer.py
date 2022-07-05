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
        
        hashmap = {None:None}
        curr = head
        dummy = None
        
        while curr:
            dummy = Node(curr.val, curr.next, curr.random)
            hashmap[curr] = dummy
            curr = curr.next
        
        curr = head
        while curr:
            dummy = hashmap[curr]
            dummy.next = hashmap[curr.next]
            dummy.random = hashmap[curr.random]
            curr = curr.next
        return hashmap[head]
    