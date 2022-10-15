/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* cur = head;
        ListNode* prev = NULL, *nxt = NULL;
        
        while(cur != NULL){
            nxt = cur->next;
            cur->next = prev;
            
            prev = cur;
            cur = nxt;
        }
        
        return prev;
    }
    
    int findLength(ListNode* cur){
        int n=0;
        while(cur != NULL){
            n++;
            cur = cur->next;
        }
        
        return n;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL || head->next == NULL || k==0) return head;
        
        int length = findLength(head);
        
        k = k % length;
        if(k == 0) return head;
        
        ListNode* slowPrev = NULL;
        ListNode* slow = head, *fast = head;
        
        while(k-->0 && fast!=NULL){
            fast = fast->next;
        }
        
        while(fast != NULL){
            slowPrev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        
        slowPrev->next = NULL;
        ListNode* slowTail = slow;
        while(slowTail->next != NULL) slowTail = slowTail->next;
        
        slowTail->next = head;
        return slow;
    }
};