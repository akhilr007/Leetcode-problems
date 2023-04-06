class Solution {
public:
    int height(TreeNode* root){
        
        if(root == NULL)
            return 0;
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        return max(lh, rh) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root == NULL)
            return 0;
        
        int diameterLeft = diameterOfBinaryTree(root->left);
        int diameterRight = diameterOfBinaryTree(root->right);
        
        int curNodeDiameter = height(root->left) + height(root->right) ; // 2 for edges
        
        return max({diameterLeft, diameterRight, curNodeDiameter});
            
        
    }
};