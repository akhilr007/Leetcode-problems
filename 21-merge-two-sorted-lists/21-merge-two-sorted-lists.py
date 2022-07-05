# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        
        if list1 == None or list2 == None:
            if list1 != None:
                return list1
            else:
                return list2
        
        dh = ListNode(-1)
        dt = dh
        
        while list1 and list2:
            if list1.val < list2.val:
                dt.next = list1
                list1 = list1.next
            else:
                dt.next = list2
                list2 = list2.next
            dt = dt.next
        
        if list1 != None:
            dt.next = list1
        if list2 != None:
            dt.next = list2
        
        return dh.next
    