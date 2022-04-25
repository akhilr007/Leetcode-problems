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
private:
    int height(TreeNode* root){
        
        if(root == NULL) return -1;
        
        return max(height(root->left), height(root->right))+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root == NULL){
            return 0;
        }
        
        int op1 = diameterOfBinaryTree(root->left);
        int op2 = diameterOfBinaryTree(root->right);
        
        int op3 = height(root->left) + height(root->right) + 2;
        
        return max(max(op1, op2), op3);
    }
};