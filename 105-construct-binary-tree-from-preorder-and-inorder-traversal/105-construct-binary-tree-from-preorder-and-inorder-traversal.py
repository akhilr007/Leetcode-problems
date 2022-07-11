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
    int findPosition(int el, vector<int>& inorder){
        
        for(int i=0; i<inorder.size(); i++){
            if(inorder[i] == el) return i;
        }
        
        return -1;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& preorder, int& idx, int instart, int inend, unordered_map<int, int>& m){
        
        if(idx >= inorder.size() || instart > inend) return NULL;
        
        int el = preorder[idx++];
        TreeNode* root = new TreeNode(el);
        int pos = m[el];
        
        root->left = buildTree(inorder, preorder, idx,  instart, pos-1, m);
        root->right = buildTree(inorder, preorder, idx, pos+1, inend, m);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n=inorder.size();
        int preOrderIndex = 0;
        
        unordered_map<int, int> m;
        for(int i=0; i<inorder.size(); i++){
            m[inorder[i]] = i;
        }
        
        TreeNode* root = buildTree(inorder, preorder, preOrderIndex, 0, n-1, m);
        return root;
    }
};