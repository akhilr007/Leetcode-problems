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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1 == NULL || list2 == NULL) return list1 != NULL ? list1 : list2;
        
        ListNode* dh = new ListNode(-1);
        ListNode* dt = dh;
        
        ListNode* c1 = list1;
        ListNode* c2 = list2;
        
        while(c1 != NULL && c2 != NULL){
            
            if(c1->val < c2->val){
                dt->next = c1;
                c1 = c1->next;
            }
            else{
                dt->next = c2;
                c2 = c2->next;
            }
            
            dt = dt->next;
        }
        
        if(c1 != NULL) dt->next = c1;
        if(c2 != NULL) dt->next = c2;
        
        return dh->next;
    }
};