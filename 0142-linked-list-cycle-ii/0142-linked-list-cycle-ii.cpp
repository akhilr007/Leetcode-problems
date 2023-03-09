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
    ListNode *detectCycle(ListNode *head) {
        
        unordered_set<ListNode*> st;
        
        ListNode* cur = head;
        
        while(cur != NULL){
            
            if(st.find(cur) != st.end())
                return cur;
            
            st.insert(cur);
            cur = cur->next;
        }
        
        return NULL;
    }
};