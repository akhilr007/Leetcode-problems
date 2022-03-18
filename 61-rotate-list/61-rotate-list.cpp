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
    int findLength(ListNode* node){
        
        int c=0;
        
        ListNode* curr = node;
        while(curr != NULL){
            curr = curr->next;
            c++;
        }
        
        return c;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL || head->next == NULL) return head;
        
        int len = findLength(head);
        k = k%len;
        
        if(k==0) return head;
        
        int c=1;
        
        ListNode* curr = head;
        while(c < len-k){
            curr = curr->next;
            c++;
        }
        
        ListNode* newHead = curr->next;
        ListNode* tail = newHead;
        curr->next = NULL;
        
        while(tail->next != NULL){
            tail = tail->next;
        }
        
        tail->next = head;
        
        return newHead;
        
        
        
    }
};