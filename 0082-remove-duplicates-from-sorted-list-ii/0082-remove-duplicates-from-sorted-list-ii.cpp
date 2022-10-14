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
    
        ListNode* dummy = new ListNode(-1);
        ListNode* dummyTail = dummy;

        ListNode* prev = head;
        ListNode* cur = head->next;

        while(cur != NULL){

            if(cur->val != prev->val){
                dummyTail->next = prev;
                dummyTail = dummyTail->next;

                prev = cur;
                cur = cur->next;
            }
            else{
                while(cur != NULL && (cur->val == prev->val)) cur = cur->next;

                prev=cur;
                if(cur) cur=cur->next;
            }
        }

        dummyTail->next = prev;
        return dummy->next;
    }
};