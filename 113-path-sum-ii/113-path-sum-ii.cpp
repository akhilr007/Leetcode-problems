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
    void pathSum(TreeNode* root, int targetSum, vector<vector<int>>& res, vector<int> sums, int sum){
        
        if(root == NULL) return;
        
        if(root->left == NULL and root->right == NULL){
            sum += root->val;
            sums.push_back(root->val);
            if(sum == targetSum){
                res.push_back(sums);
                return;
            }
            else return;
        }
        
        sum += root->val;
        sums.push_back(root->val);
        
        pathSum(root->left, targetSum, res, sums, sum);
        pathSum(root->right, targetSum, res, sums, sum);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> res;
        vector<int> sums;
        pathSum(root, targetSum, res, sums, 0);
        return res;
    }
};