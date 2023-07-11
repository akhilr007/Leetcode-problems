/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void mapParentNode(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& nodeToParent){
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            
            int size=q.size();
            while(size--){
                
                auto node = q.front();
                q.pop();
                
                if(node->left)
                {
                    q.push(node->left);
                    nodeToParent[node->left] = node;
                }
                
                if(node->right)
                {
                    q.push(node->right);
                    nodeToParent[node->right] = node;
                }
            }
        }
    }
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<int> result;
        if(root == NULL)
            return result;
        
        unordered_map<TreeNode*, TreeNode*> nodeToParent;
        mapParentNode(root, nodeToParent);
        
        queue<TreeNode*> q;
        q.push(target);
        
        unordered_map<TreeNode*, bool> visited;
        visited[target] = true;
        
        int level=0;
        
        while(!q.empty()){
            
            if(level == k)
                    break;
            level++;
                    
            int size = q.size();
            while(size--){
                
                auto node = q.front();
                q.pop();
                
                if(node->left and visited[node->left]==false){
                    visited[node->left] = true;
                    q.push(node->left);
                }
                
                if(node->right and visited[node->right]==false){
                    visited[node->right] = true;
                    q.push(node->right);
                }
                
                if(nodeToParent[node] and visited[nodeToParent[node]]==false){
                    visited[nodeToParent[node]] = true;
                    q.push(nodeToParent[node]);
                }
            }
        }
        
        while(!q.empty()){
            result.push_back(q.front()->val);
            q.pop();
        }
        
        return result;
    }
};