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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       
        ListNode* curr = head;
        int c=0;
        
        while(curr != NULL){
            curr=curr->next;
            c++;
        }
        
        int gap = c-n;
        
        if(gap == 0){
            ListNode* node = head;
            ListNode* newHead = head->next;
            delete(node);
            return newHead;
        }
        
        curr = head;
        
        for(int i=1; i<gap; i++){
            curr = curr->next;
        }
        
        ListNode* node = curr->next;
        curr->next = curr->next->next;
        delete(node);
        return head;
    }
};