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
    int res = INT_MAX;
    TreeNode* prevNode = NULL;
    
    void inorder(TreeNode* root){
        
        if(root == NULL)
            return;
        
        inorder(root->left);
        if(prevNode != NULL){
            res = min(res, root->val - prevNode->val);
        }
        prevNode = root;
        inorder(root->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        
        inorder(root);
        return res;
    }
};