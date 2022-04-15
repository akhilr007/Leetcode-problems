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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        
        if(root == NULL){
            return NULL;
        }
        
        // if root->val is lower than low value then ans should lie in right subtree
        if(root->val < low){
            return trimBST(root->right, low, high);
        }
        // if root->val is higher than high value then ans should lie in left subtree
        else if(root->val > high){
            return trimBST(root->left, low, high);
        }
        
        // else the root is in range then check for left subtree and right subtree
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};