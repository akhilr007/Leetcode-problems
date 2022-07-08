# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def merge(self, l1, l2):
        
        if l1 == None or l2 == None:
            if l1 != None: return l1
            else: return l2
        
        c1, c2 = l1, l2
        
        dh = ListNode(-1)
        dt = dh
        
        while c1 and c2:
            if c1.val < c2.val:
                dt.next = c1
                c1 = c1.next
            else:
                dt.next = c2
                c2 = c2.next
            dt = dt.next
        
        if c1:
            dt.next = c1
        if c2:
            dt.next = c2
        
        return dh.next
    
    def mergeSort(self, lists, si, ei):
        if si > ei:
            return None
        if si == ei:
            return lists[si]
        
        mid = (si + ei)//2
        
        l1 = self.mergeSort(lists, si, mid)
        l2 = self.mergeSort(lists, mid+1, ei)
        
        return self.merge(l1, l2)
    
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        
        if len(lists) == 0:
            return None
        
        return self.mergeSort(lists, 0, len(lists)-1)