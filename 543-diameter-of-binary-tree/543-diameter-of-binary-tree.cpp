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
private:
    int height(TreeNode* root){
        
        if(root == NULL) return -1;
        
        int left = height(root->left);
        int right = height(root->right);
        
        return max(left, right)+1;
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root == NULL) return 0;
        
        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);
        
        int diaWithRoot = height(root->left) + height(root->right) + 2;
        
        return max(leftDiameter, max(rightDiameter, diaWithRoot) );
    }
};