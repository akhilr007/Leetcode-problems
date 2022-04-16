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
    void rwsol(TreeNode* root, int& sum){
        
        if(root == NULL) return;
        
        rwsol(root->right, sum);
        int temp = root->val;
        sum += temp;
        root->val = sum;
        
        rwsol(root->left, sum);
        
    }
    
    TreeNode* convertBST(TreeNode* root) {
        
        int sum=0;
        rwsol(root, sum);
        return root;
    }
};