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
    int height(TreeNode* root, int& diameter){
        
        if(root == NULL)
            return -1; // due to edges
        
        
        int leftHeight = height(root->left, diameter);
        int rightHeight = height(root->right, diameter);
        
        diameter = max(diameter, leftHeight + rightHeight + 2);
        
        return max(leftHeight, rightHeight) + 1;
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};