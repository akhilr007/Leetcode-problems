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
    ListNode* swapNodes(ListNode* head, int k) {
        
        vector<ListNode*> nodes;
        
        ListNode* curr = head;
        
        while(curr != NULL){
            
            nodes.push_back(curr);
            curr = curr->next;
        }
        
        int len = nodes.size();
        
        int temp = nodes[k-1]->val;
        nodes[k-1]->val = nodes[len-k]->val;
        nodes[len-k]->val = temp;
        
        return nodes[0];
    }
};