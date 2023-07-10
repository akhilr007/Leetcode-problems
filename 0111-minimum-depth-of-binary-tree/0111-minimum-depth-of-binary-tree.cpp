class Solution {
public:
    int bfs(TreeNode* root){
        
        if(root==NULL)
            return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        int depth=1;
        
        while(q.size()>0){
            
            int size = q.size();
            while(size--){
                
                auto node = q.front();
                q.pop();
                
                if(node->left == NULL and node->right == NULL)
                    return depth;
                
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            
            depth++;
        }
        
        return depth;
    }
    
    int solve(TreeNode* root){
        
        if(root == NULL)
            return 1e8;
        
        if(root->left == NULL and root->right == NULL)
            return 1;
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        return 1 + min(left, right);  
    }
    
    int minDepth(TreeNode* root) {
        
        return bfs(root);
    }
};