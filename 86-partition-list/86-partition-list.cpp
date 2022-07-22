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
    ListNode* partition(ListNode* head, int x) {
        
        if(head == NULL or head->next == NULL) return head;
        
        ListNode* dh1 = new ListNode(-1);
        ListNode* dt1 = dh1;
        
        ListNode* dh2 = new ListNode(-1);
        ListNode* dt2 = dh2;
        
        ListNode* curr = head;
        
        while(curr!= NULL){
            
            if(curr->val < x){
                dt1->next = curr;
                dt1 = dt1->next;
            }
            else{
                dt2->next = curr;
                dt2 = dt2->next;
            }
            curr = curr->next;
        }
        
        dt2->next = NULL;
        dt1->next = dh2->next;
        return dh1->next;
    }
};