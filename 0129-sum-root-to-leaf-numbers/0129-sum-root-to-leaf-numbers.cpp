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
    int findSum(TreeNode* root, int totalsum){
        if(root == NULL)
            return 0;
        if(root->left == NULL and root->right == NULL)
            return totalsum + root->val;
        
        int sum = totalsum + root->val;
        
        int lsum = findSum(root->left, sum * 10);
        int rsum = findSum(root->right, sum * 10);
        
        return lsum+rsum;
    }
    
    int sumNumbers(TreeNode* root) {
        
        if(root == NULL)
            return 0;
        
        return findSum(root, 0);
    }
};