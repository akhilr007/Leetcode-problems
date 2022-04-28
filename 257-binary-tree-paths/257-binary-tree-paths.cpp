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
    void findPath(TreeNode* root, vector<string>& paths, string res){
        
        if(root->left == NULL and root->right == NULL){
            paths.push_back(res);
            return;
        }
        
        if(root->left){
            findPath(root->left, paths, res + "->" + to_string(root->left->val));
        }
        if(root->right){
            findPath(root->right, paths, res + "->" + to_string(root->right->val));
        }
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> paths;
        string res="";
        findPath(root, paths, res + to_string(root->val));
        return paths;
    }
};