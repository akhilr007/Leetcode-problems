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
    private int findLength(ListNode node){
        int n=0;
        while(node != null){
            n++;
            node = node.next;
        }
        
        return n;
    }
    
    static ListNode tempHead = null;
    static ListNode tempTail = null;
    private void addFirst(ListNode node){
        if(tempHead == null){
            tempHead = node;
            tempTail = node;
        }
        else{
            node.next = tempHead;
            tempHead = node;
        }
         
    }
    
    public ListNode reverseKGroup(ListNode head, int k) {
        
        if(head == null || head.next == null || k == 1) return head;
        
        ListNode cur = head;
        int length = findLength(head);
        
        ListNode originalHead = null, originalTail = null;
        
        while(length >= k){
            int tempK = k;
            
            while(tempK-- > 0){
                ListNode nxt = cur.next;
                cur.next = null;
                
                addFirst(cur);
                cur = nxt;
            }
            
            if(originalHead == null){
                originalHead = tempHead;
                originalTail = tempTail;
                System.out.println(originalHead.val + " " + originalTail.val);
            }
            else{
                originalTail.next = tempHead;
                originalTail = tempTail;
            }
            
            tempHead = tempTail = null;
            length -= k;
        }
        
        originalTail.next = cur;
        return originalHead;
    }
}