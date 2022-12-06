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
    public ListNode oddEvenList(ListNode head) {
        
        if(head == null || head.next == null || head.next.next == null) 
            return head;
        
        ListNode oddH = new ListNode(-1);
        ListNode oddT = oddH;
        
        ListNode evenH = new ListNode(-1);
        ListNode evenT = evenH;
        
        ListNode cur = head;
        boolean flag = false;
        
        while(cur != null){
            
            if(flag == true){
                evenT.next = cur;
                evenT = evenT.next;
            }
            else{
                oddT.next = cur;
                oddT = oddT.next;
            }
            
            cur = cur.next;
            flag = !flag;
        }
        
        oddT.next = null;
        evenT.next = null;
        
        oddT.next = evenH.next;
        return oddH.next;
        
    }
}