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

        ListNode* slow = node;
        ListNode* fast = node;

        while(fast->next != NULL && fast->next->next != NULL){

            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverse(ListNode* node){

        if(node == NULL || node->next == NULL) return node;

        ListNode* curr = node;
        ListNode* prev = NULL, *next = NULL;

        while(curr != NULL){

            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }
    
    void reorderList(ListNode* head) {
        
        ListNode* mid = findMid(head);
        ListNode* sh = mid->next;
        
        mid->next = NULL;
        
        ListNode* t1 = head;
        ListNode* t2 = reverse(sh);
        
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        
        bool flag = true;
        
        while(t1 != NULL && t2 != NULL){
            
            if(flag == true){
                prev->next = t1;
                t1 = t1->next;
            }
            else{
                prev->next = t2;
                t2 = t2->next;
            }
            
            prev=prev->next;
            flag = !flag;
        }
        
        if(t1 != NULL) prev->next = t1;
        if(t2 != NULL) prev->next = t2;
        
    }
};