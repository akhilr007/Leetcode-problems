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
    int util(TreeNode* root, int& res){
        
        if(root == NULL) return 0;
        
        int leftMax = util(root->left, res);
        int rightMax = util(root->right, res);
        leftMax = max(0, leftMax);
        rightMax = max(0, rightMax);
        
        res = max(res, root->val +leftMax + rightMax);
        
        return root->val + max(leftMax, rightMax);
    }
    
    int maxPathSum(TreeNode* root) {
        
        int res = root->val;
        util(root, res);
        return res;
    }
};