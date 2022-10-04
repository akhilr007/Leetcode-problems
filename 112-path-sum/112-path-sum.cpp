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
    bool helper(TreeNode* root, int sum, int targetSum){
        
        if(root == NULL) return false;
        
        if(root->left == NULL and root->right == NULL){
            sum += root->val;
            if(sum == targetSum) return true;
            else return false;
        }
        
        sum += root->val;
        
        bool left = helper(root->left, sum, targetSum);
        bool right = helper(root->right, sum, targetSum);
        
        return left || right; 
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root == NULL) return false;
        int sum = 0;
        return helper(root, sum, targetSum);
    }
};