/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root){
        if(root == NULL) return -1;
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        return max(lh, rh) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        
        int d1 = diameterOfBinaryTree(root->left);
        int d2 = diameterOfBinaryTree(root->right);
        
        int d3 = height(root->left) + height(root->right) + 2;
        
        return max(max(d1, d2), d3);
        
    }
};