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
    int findLength(ListNode* head){
        
        int c=0;
        ListNode* curr = head;
        
        while(curr != NULL){
            curr = curr->next;
            c++;
        }
        
        return c;
    }
    
    ListNode* th = NULL, *tt = NULL;
    void addFirst(ListNode* node){
        
        if(th == NULL){
            th = node;
            tt = node;
        }
        else{
            node->next = th;
            th = node;
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head == NULL || head->next == NULL ) return head;
        
        int n = findLength(head);
        
        ListNode* oh = NULL, *ot = NULL;
        
        ListNode* curr = head;
        
        while(n >= k){
            
            int tempK = k;
            while(tempK-- > 0){
                
                ListNode* forw = curr->next;
                curr->next = NULL;
                
                addFirst(curr);
                curr = forw;
            }
            
            if(oh == NULL){
                oh = th;
                ot = tt;
            }
            else{
                ot->next = th;
                ot = tt;
            }
            
            th = NULL;
            tt = NULL;
            n -= k;
        }
        
        ot->next = curr;
        return oh;
    }
};