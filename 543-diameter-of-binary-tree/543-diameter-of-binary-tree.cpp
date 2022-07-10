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
    int diameterFast(TreeNode* root, int& diameter){
        
        if(root == NULL) return -1;
        
        int lh = diameterFast(root->left, diameter);
        int rh = diameterFast(root->right, diameter);
        
        diameter = max(diameter, lh + rh + 2);
        
        return max(lh, rh) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        int diameter = 0;
        diameterFast(root, diameter);
        return diameter;
    }
};