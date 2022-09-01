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
    int countGoodNodes(TreeNode* root, int maxVal, int& res){
        
        if(root == NULL) return 0;
        
        res += root->val >= maxVal ? 1 : 0;
        
        countGoodNodes(root->left, max(root->val, maxVal), res);
        countGoodNodes(root->right, max(root->val, maxVal), res);
        
        return res;
    }
    
    int goodNodes(TreeNode* root) {
        
        int res = 0;
        return countGoodNodes(root, root->val, res);
    }
};