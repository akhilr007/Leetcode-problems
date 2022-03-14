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
    ListNode* oddEvenList(ListNode* head) {
        
        ListNode* dh1 = new ListNode(-1);
        ListNode* dt1 = dh1;
        
        ListNode* dh2 = new ListNode(-1);
        ListNode* dt2 = dh2;
        
        ListNode* curr = head;
        int node=1;
        
        while(curr != NULL){
            
            if(node%2==0){
                dt2->next = curr;
                dt2 = dt2->next;
            }
            else{
                dt1->next = curr;
                dt1 = dt1->next;
            }
            
            node++;
            curr = curr->next;
        }
        
        dt1->next = NULL;
        dt2->next = NULL;
        
        dt1->next = dh2->next;
        return dh1->next;
    }
};