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
    ListNode findMid(ListNode head){
        ListNode slow = head, fast = head;
        while(fast.next != null && fast.next.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
    
    ListNode reverseList(ListNode head){
        ListNode prev = null, cur=head;
        while(cur != null){
            ListNode nxt = cur.next;
            cur.next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
    
    public void reorderList(ListNode head) {
        
        if(head == null || head.next == null || head.next.next == null) return ;
        
        ListNode mid = findMid(head);
        ListNode t2 = mid.next;
        mid.next = null;

        ListNode t1 = head;
        t2 = reverseList(t2);
        
        ListNode dummy = new ListNode(-1);
        ListNode dt = dummy;
        
        boolean flag=false;
        while(t1 != null && t2 != null){
            if(!flag){
                dt.next = t1;
                t1 = t1.next;
            }
            else{
                dt.next = t2;
                t2 = t2.next;
            }
            flag = !flag;
            dt = dt.next;
        }
        
        if(t1 != null) dt.next = t1;
        if(t2 != null) dt.next = t2;
        
    }
}