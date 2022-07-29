/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& oldToNew){
        
        if(oldToNew.find(node) != oldToNew.end()){
            return oldToNew[node];
        }
        
        Node* copy = new Node(node->val);
        oldToNew[node] = copy;
        
        for(auto nbr: node->neighbors){
            copy->neighbors.push_back(dfs(nbr, oldToNew));
        }
        
        return copy;
    }
    
    Node* cloneGraph(Node* node) {
        if(node == NULL) return node;
        unordered_map<Node*, Node*> oldToNew;
        
        return dfs(node, oldToNew);
    }
};