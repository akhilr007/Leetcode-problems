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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& preorder, int& index, int inorderStart, int inorderEnd, int n, unordered_map<int, int>& mp){
        
        if(index >= n || inorderStart > inorderEnd){
            return NULL;
        }
        
        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);
        int position = mp[element];
        
        root->left = buildTree(inorder, preorder, index, inorderStart, position-1, n, mp);
        root->right = buildTree(inorder, preorder, index, position+1, inorderEnd, n, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = inorder.size();
        
        int preOrderIndex=0;
        
        // create mapping of nodes
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[inorder[i]] = i;
        }
        
        TreeNode* root = buildTree(inorder, preorder, preOrderIndex, 0, n-1, n, mp);
        return root;
    }
};