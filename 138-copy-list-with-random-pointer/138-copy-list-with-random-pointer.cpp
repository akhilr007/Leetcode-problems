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
        
        unordered_map<Node*, Node*> mp;
        
        Node* curr = head;
        Node* dummy = NULL;
        
        while(curr != NULL){
            
            dummy = new Node(curr->val);
            mp[curr] = dummy;
            curr = curr->next;
        }
        
        curr = head;
        while(curr != NULL){
            
            dummy = mp[curr];
            dummy->next = mp[curr->next];
            dummy->random = mp[curr->random];
            curr = curr->next;
        }
        
        return mp[head];
        
    }
};