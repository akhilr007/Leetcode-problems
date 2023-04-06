class Solution {
public:
    int height(TreeNode* root){
        
        if(root == NULL)
            return 0;
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        return max(lh, rh) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        
        if(root == NULL)
            return true;
        
        bool leftSubtree = isBalanced(root->left);
        bool rightSubtree = isBalanced(root->right);
        
        bool ans = abs(height(root->left) - height(root->right)) <= 1;
        
        return leftSubtree and rightSubtree and ans;
    }
};