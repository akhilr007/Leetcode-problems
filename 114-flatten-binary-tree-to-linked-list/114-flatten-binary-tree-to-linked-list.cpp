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
    void helper(TreeNode* root, TreeNode*& prev){
        
        if(root == NULL) return;
        
        helper(root->right, prev);
        helper(root->left, prev);
        
        root->left = NULL;
        root->right = prev;
        prev = root;
    }
    
    void flatten(TreeNode* root) {
        
        if(root == NULL) return;
        
        TreeNode* prev = NULL;
        helper(root, prev);
    }
};