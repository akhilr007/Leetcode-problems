class Solution {
public:
    
    
    int countNodes(TreeNode* root) {
        
        if(root == NULL)
            return 0;
        
        int lh = findLeftHeight(root);
        int rh = findRightHeight(root);
        
        if(lh == rh)
            return (1 << lh) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
    int findLeftHeight(TreeNode* root){
        
        int height=0;
        while(root){
            height++;
            root = root->left;
        }
        
        return height;
    }
    
    int findRightHeight(TreeNode* root){
        
        int height=0;
        while(root){
            height++;
            root = root->right;
        }
        
        return height;
    }
};