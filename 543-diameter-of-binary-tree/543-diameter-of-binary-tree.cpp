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
    pair<int, int> diameterFast(TreeNode* root){
        
        if(root == NULL){
            pair<int, int> p = make_pair(0 , -1);
            return p;
        }
        
        auto left = diameterFast(root->left);
        auto right = diameterFast(root->right);
        
        int op1 = left.first;
        int op2 = right.first;
        
        int op3 = left.second + right.second + 2;
        
        pair<int, int> ans;
        ans.first = max(max(op1, op2), op3);
        ans.second = max(left.second, right.second)+1;
        
        return ans;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        return diameterFast(root).first;
    }
};