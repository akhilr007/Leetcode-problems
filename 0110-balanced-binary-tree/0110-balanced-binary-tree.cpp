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
    int findHeight(TreeNode* root){
        
        if(root == NULL)
            return 0;
        
        int lh = findHeight(root->left);
        int rh = findHeight(root->right);
        
        return max(lh, rh) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        
        if(root == NULL)
            return true;
        
        bool leftIsBalanced = isBalanced(root->left);
        bool rightIsBalanced = isBalanced(root->right);
        
        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);
        
        bool absDiff = abs(leftHeight - rightHeight) <= 1;
        
        return leftIsBalanced and rightIsBalanced && absDiff;
    }
};