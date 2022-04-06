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
    void f(TreeNode* root, vector<int>& inorder){
        
        if(root == NULL) return;
        
        f(root->left, inorder);
        inorder.push_back(root->val);
        f(root->right, inorder);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        f(root, inorder);
        
        return inorder;
    }
};