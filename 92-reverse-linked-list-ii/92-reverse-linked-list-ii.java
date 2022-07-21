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
    public ListNode reverse(ListNode curr){
        ListNode prev = null, nxt = null;
        
        while(curr != null){
            nxt = curr.next;
            curr.next = prev;
            
            prev = curr;
            curr = nxt;
        }
        
        return prev;
    }
    
    public ListNode reverseBetween(ListNode head, int left, int right) {
        
        if (head == null || head.next == null) return head;
        
        ListNode curr = head, prev = null;
        int count = 1;
        
        while(count != left){
            prev = curr;
            curr = curr.next;
            count += 1;
        }
        
        ListNode start = curr;
        while(count != right){
            curr = curr.next;
            count += 1;
        }
        
        ListNode tail = curr.next;
        curr.next = null;
        
        ListNode newhead = reverse(start);
        
        if(prev != null) prev.next = newhead;
        
        curr = newhead;
        while(curr.next != null){
            curr = curr.next;
        }
        
        curr.next = tail;
        
        if(left == 1) return newhead;
        return head;
    }
}