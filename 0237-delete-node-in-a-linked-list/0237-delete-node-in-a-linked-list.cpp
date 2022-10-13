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
    void deleteNode(ListNode* node) {
        
        ListNode* nodeNext = node->next; //1
        
        node->val = nodeNext->val;
        node->next = nodeNext->next;
        
        
    }
};