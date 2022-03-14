/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head == NULL) return NULL;
        
        Node* curr = head;
        
        while(curr != NULL){
            
            Node* dummy = new Node(curr->val);
            
            // get hold of next node of curr
            Node* next = curr->next;
            
            curr->next = dummy;
            
            dummy->next = next;
            
            curr = next;
            
        }
        
        curr = head;
        
        while(curr != NULL){
            
            curr->next->random = curr->random == NULL ? NULL : curr->random->next;
            curr = curr->next->next;
        }
        
        Node* c1 = head;
        Node* c2 = head->next;
        
        Node* ans = head->next;
        
        while(c1 != NULL && c2 != NULL){
            
            Node* n1 = c2->next;
            Node* n2 = n1 == NULL ? NULL : n1->next;
            
            c1->next = n1;
            c2->next = n2;
            
            c1 = n1;
            c2 = n2;
        }
        
        return ans;
        
        
    }
};