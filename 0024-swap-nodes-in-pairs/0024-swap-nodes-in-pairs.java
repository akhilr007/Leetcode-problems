/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        
        if(head == null || head.next == null) return head;
        
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        
        ListNode prev = dummy;
        
        while(prev.next != null && prev.next.next != null){
            
            ListNode cur = prev.next;
            ListNode curNxt = cur.next;
            ListNode temp = curNxt.next;
            
            prev.next = curNxt;
            curNxt.next = cur;
            cur.next = temp;
            
            prev = cur;
        }
        
        return dummy.next;
    }
}