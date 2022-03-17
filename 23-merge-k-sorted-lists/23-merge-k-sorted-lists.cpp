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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        
        int k=lists.size();
        for(int i=0; i<k; i++){
            if(lists[i] != NULL){
                pq.push({lists[i]->val, lists[i]});
            }
        }
        
        if(pq.size()==0) return NULL;
        
        ListNode* dh = new ListNode(-1);
        ListNode* dt = dh;
        
        while(pq.size()>0){
            
            pair<int, ListNode*> curr = pq.top();
            pq.pop();
            
            int val = curr.first;
            ListNode* add = curr.second;
            
            dt->next = add;
            dt = dt->next;
            
            if(add->next != NULL){
                pq.push({add->next->val, add->next});
            }
        }
        
        return dh->next;
    }
};