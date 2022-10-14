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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* dh = new ListNode(-1);
        ListNode* dt = dh;

        ListNode* prev = NULL;
        ListNode* cur = head;

        while(cur != NULL){

            if(prev == NULL || prev->val != cur->val){
                dt->next = cur;
                dt = dt->next;

                prev = cur;
               
            }
            
            cur = cur->next;
        }

        dt->next = NULL;
        return dh->next;
    }
};