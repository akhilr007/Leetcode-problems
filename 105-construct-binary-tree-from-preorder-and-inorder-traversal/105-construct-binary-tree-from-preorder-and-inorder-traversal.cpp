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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int instart, int inend, int& index, unordered_map<int, int>& m){
        
        if(index >= inorder.size() or instart > inend) return NULL;
        
        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);
        int pos = m[element];
        
        root->left = helper(preorder, inorder, instart, pos-1, index, m);
        root->right = helper(preorder, inorder, pos+1, inend, index, m);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int preorderind = 0;
        
        int n = inorder.size();
        unordered_map<int, int> m;
        for(int i=0; i<inorder.size(); i++){
            m[inorder[i]] = i;
        }
        
        return helper(preorder, inorder, 0, n, preorderind, m);
    }
};