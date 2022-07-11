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
    void kthSmallestUtil(TreeNode* root, int k, int& count, int& ans){
        
        if(root == NULL) return;
        
        kthSmallestUtil(root->left, k, count, ans);
        
        count += 1;
        if(count == k){
            ans = root->val;
            return;
        }
        
        kthSmallestUtil(root->right, k, count, ans);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        
        int ans = 0;
        int count=0;
        kthSmallestUtil(root, k, count, ans);
        return ans;
    }
};