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
    
    ListNode* findMid(ListNode* node){
        
        if(node == NULL || node->next == NULL) return node;
        
        ListNode* slow = node, *fast = node;
        
        while(fast->next != NULL && fast->next->next != NULL){
            
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* reverse(ListNode* node){
        
        if(node == NULL || node->next == NULL) return node;
        
        ListNode* curr = node;
        ListNode* prev = NULL, *next = NULL;
        
        while(curr != NULL){
            
            next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        
        ListNode* midNode = findMid(head);
        ListNode* midNodeNext = midNode->next;
        
        midNode->next = NULL;
        
        ListNode* t1 = head;
        ListNode* t2 = reverse(midNodeNext);
        
        while(t2 != NULL){
            
            if(t1->val != t2->val){
                return false;
            }
            
            t1 = t1->next;
            t2 = t2->next;
        }
        
        return true;
        
    }
};