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
    public ListNode partition(ListNode head, int x) {
        
        if(head == null) return null;
        
        ListNode dh = new ListNode(-1);
        ListNode dt = dh;
        
        ListNode dh1 = new ListNode(-1);
        ListNode dt1 = dh1;
        
        ListNode curr = head;
        while(curr != null){
            if(curr.val < x){
                dt.next = curr;
                dt = dt.next;
            }
            else{
                dt1.next = curr;
                dt1 = dt1.next;
            }
            curr = curr.next;
        }
        
        dt1.next = null;
        dt.next = dh1.next;
        return dh.next;
    }
}