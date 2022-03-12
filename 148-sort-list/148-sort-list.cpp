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
    ListNode* findMid(ListNode* node){
        
        if(node == NULL || node->next == NULL) return node;
        
        ListNode* slow = node, *fast = node;
        
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2){
        
        if(l1 == NULL || l2 == NULL) return l1 != NULL ? l1 : l2;
        
        ListNode* dh = new ListNode(-1);
        ListNode* dt = dh;
        
        ListNode* c1 = l1;
        ListNode* c2 = l2;
        
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
    
    ListNode* sortList(ListNode* head) {
        
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* mid = findMid(head);
        ListNode* sh = mid->next;
        mid->next = NULL;
        
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(sh);
        
        return merge(l1, l2);
    }
};