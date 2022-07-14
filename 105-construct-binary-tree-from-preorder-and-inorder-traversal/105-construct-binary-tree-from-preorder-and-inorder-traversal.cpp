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
    int findElementInInorder(int val, vector<int>& inorder){
        
        for(int i=0; i<inorder.size(); i++){
            if(inorder[i] == val) return i;
        }
        return -1;
    }
    
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int instart, int inend, int& index){
        
        if(index >= inorder.size() or instart > inend) return NULL;
        
        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);
        int pos = findElementInInorder(element, inorder);
        
        root->left = helper(preorder, inorder, instart, pos-1, index);
        root->right = helper(preorder, inorder, pos+1, inend, index);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int preorderind = 0;
        
        int n = inorder.size();
        
        return helper(preorder, inorder, 0, n, preorderind);
    }
};