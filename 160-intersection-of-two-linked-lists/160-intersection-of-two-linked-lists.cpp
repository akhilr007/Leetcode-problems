/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int length(ListNode* head){
        
        int c=0;
        while(head != NULL){
            
            c++;
            head = head->next;
        }
        
        return c;
    }
    
    ListNode *getIntersectionNode(ListNode *l1, ListNode *l2) {
        
        int n1 = length(l1);
        int n2 = length(l2);
        
        int delta = abs(n1 - n2);
        
        ListNode* c1 = l1;
        ListNode* c2 = l2;
        
        if(n1 > n2){
            
            while(delta-- > 0){
                c1 = c1->next;
            }
        }
        else{
            
            while(delta-- > 0){
                c2 = c2->next;
            }
        }
        
        while(c1 != c2){
            
            c1 = c1->next;
            c2 = c2->next;
        }
        
        return c1;
    }
};