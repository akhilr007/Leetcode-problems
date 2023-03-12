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
    // time complexity -> O(N * logK) -> N -> (size of l1 and l2)
    ListNode* merge(ListNode* l1, ListNode* l2){
        
        if(l1 == NULL || l2 == NULL){
            return l1 != NULL ? l1 : l2;
        }
        
        ListNode* c1 = l1;
        ListNode* c2 = l2;
        
        ListNode* dh = new ListNode(-1);
        ListNode* dt = dh;
        
        while(c1 != NULL && c2 != NULL){
            
            if(c1->val <= c2->val){
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
    
    ListNode* mergeList(vector<ListNode*>& lists, int s, int e){
        
        if(s == e)
            return lists[s];
        
        int mid = (s + e) / 2;
        
        ListNode* l1 = mergeList(lists, s, mid);
        ListNode* l2 = mergeList(lists, mid+1, e);
        
        ListNode* l = merge(l1, l2);
        return l;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size() == 0)
            return NULL;
        return mergeList(lists, 0, lists.size()-1);
    }
};