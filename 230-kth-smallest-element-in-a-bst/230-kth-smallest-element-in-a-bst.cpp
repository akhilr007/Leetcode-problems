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
    void findInorder(TreeNode* root, int k, vector<int>& ans){
        
        if(root == NULL){
            return;
        }
        
        findInorder(root->left, k, ans);
        ans.push_back(root->val);
        findInorder(root->right, k, ans);
        
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        findInorder(root, k, ans);
        
       // 1 2 3 4 5 6r
        return ans[k-1];
    }
};