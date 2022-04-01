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
    void solve(TreeNode* root, string sum, int& totalSum){
        
        if(root == NULL) return;
        
        if(root->left == NULL and root->right == NULL){
            
            sum += to_string(root->val);
            
            totalSum += stoi(sum);
            return;
        }
        
        sum += to_string(root->val);
        
        solve(root->left, sum, totalSum);
        solve(root->right, sum, totalSum);
        
    }
    
    int sumNumbers(TreeNode* root) {
        
        if(root == NULL) return 0;
        
        int totalSum=0;
        
        solve(root, "", totalSum);
        
        return totalSum;
    }
};