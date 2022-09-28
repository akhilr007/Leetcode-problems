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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        
        ListNode dh = new ListNode(-1);
        dh.next = head;
        
        ListNode left = dh;
        ListNode right = head;
        
        while(n>0 && right != null){
            right = right.next;
            n--;
        }
        
        while(right != null){
            left = left.next;
            right = right.next;
        }
        
        left.next = left.next.next;
        return dh.next;
        
        
    }
}