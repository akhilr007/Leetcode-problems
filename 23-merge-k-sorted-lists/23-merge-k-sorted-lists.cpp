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
    
    ListNode* merge(ListNode* l1, ListNode* l2){
        
        if(l1 == NULL || l2 == NULL) return l1 != NULL ? l1 : l2;
        
        ListNode* dh = new ListNode(-1);
        ListNode* dt = dh;
        
        ListNode* c1 = l1, *c2=l2;
        
        while(c1 != NULL && c2 != NULL){
            
            if(c1->val < c2->val){
                
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
    
    ListNode* mergeKLists(vector<ListNode*> lists, int si, int ei){
        
        if(si > ei) return NULL;
        if(si == ei) return lists[si];
        
        int mid = si + (ei-si)/2;
        
        ListNode* l1 = mergeKLists(lists, si, mid);
        ListNode* l2 = mergeKLists(lists, mid+1, ei);
        
        return merge(l1, l2);
        
        
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size() == NULL) return NULL;
        
        return mergeKLists(lists, 0, lists.size()-1);
    }
};