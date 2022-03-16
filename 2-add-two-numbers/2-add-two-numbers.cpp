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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(l1 == NULL && l2 == NULL) return NULL;
        
        if(l1 == NULL || l2 == NULL) return l1 != NULL ? l1 : l2;
        
        ListNode* dh = new ListNode(-1);
        ListNode* dt = dh;

        ListNode *c1 = l1;
        ListNode *c2 = l2;

        int c=0;

        while(c1 != NULL || c2 != NULL){
            

            int a = c1==NULL ? 0 : c1->val;
            int b = c2==NULL ? 0 : c2->val;

            int sum = a + b + c;

            ListNode* nn = new ListNode(sum%10);
            c = sum/10;

            dt->next = nn;

            dt = dt->next;

            if(c1 != NULL) c1 = c1->next;
            if(c2 != NULL) c2 = c2->next;
        }

        if(c > 0){
            ListNode* nn = new ListNode(1);
            dt->next = nn;
            dt = dt->next;
        }

        return dh->next;
    }
};