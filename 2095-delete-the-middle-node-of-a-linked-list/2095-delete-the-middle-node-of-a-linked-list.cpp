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
    ListNode* deleteMiddle(ListNode* head) {
        
        if(head == NULL || head->next == NULL) return NULL;
        
        ListNode* slow = head, *slowBehind = head, *fast = head;
        while(fast != NULL && fast->next != NULL){
            slowBehind = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slowBehind->next = slow->next;
        delete slow;
        return head;
    }
};