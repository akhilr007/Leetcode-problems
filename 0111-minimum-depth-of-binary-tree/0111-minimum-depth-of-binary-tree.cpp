class Solution {
public:
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
        
        if(root == NULL)
            return 0;
        
        return solve(root);
    }
};