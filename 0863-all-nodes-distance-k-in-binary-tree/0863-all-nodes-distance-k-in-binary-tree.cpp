class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent){
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            
            auto node = q.front();
            q.pop();
            
            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*, TreeNode*> parent;
        markParents(root, parent);
        
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        
        int level=0;
        while(!q.empty()){
            
            int size = q.size();
        
            if(level == k) break;
            level++;
            
            for(int i=0; i<size; i++){
                
                auto node = q.front();
                q.pop();
                
                if(node->left && visited[node->left] == false){
                    q.push(node->left);
                    visited[node->left] = true;
                }
                
                if(node->right && visited[node->right] == false){
                    q.push(node->right);
                    visited[node->right] = true;
                }
                
                if(parent[node] && visited[parent[node]] == false){
                    q.push(parent[node]);
                    visited[parent[node]] = true;
                }
            }
        }
        
        vector<int> nodes;
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            
            nodes.push_back(node->val);
        }
        
        return nodes;
    }
};