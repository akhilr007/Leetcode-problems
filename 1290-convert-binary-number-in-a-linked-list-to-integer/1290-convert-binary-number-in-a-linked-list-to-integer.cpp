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
        ListNode* curr = head, *prev = NULL, *nxt = NULL;
        
        while(curr != NULL){
            nxt = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = nxt;
        }
        
        return prev;
    }
    
    int getDecimalValue(ListNode* head) {
        
        ListNode* curr = reverse(head);
        double p=0;
        
        double val=0;
        
        while(curr != NULL){
            
            if(curr->val == 1){
                val += pow((double)2, p);
                p++;
            }
            else{
                p++;
            }
            
            curr = curr->next;
            
        }
        
        return (int)val;
    }
};