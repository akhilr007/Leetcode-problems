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
    public ListNode deleteDuplicates(ListNode head) {
        
        if(head == null || head.next == null) return head;
        
        ListNode prev = null;
        ListNode cur = head;
        
        ListNode dh = new ListNode(-1);
        ListNode dt = dh;
        
        while(cur != null){
            
            if(prev == null || prev.val != cur.val){
                dt.next = cur;
                dt = dt.next;
                
                prev = cur;
                cur = cur.next;
            }
            else cur = cur.next;
        }
        
        dt.next = null;
        return dh.next;
    }
}