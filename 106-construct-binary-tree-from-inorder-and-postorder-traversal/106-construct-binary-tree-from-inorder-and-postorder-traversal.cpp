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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int& index, int postorderStart, int postorderEnd, unordered_map<int, int>& mp){
        
        if(index < 0 || postorderStart > postorderEnd){
            return NULL;
        }
        
        int element = postorder[index--];
        TreeNode* root = new TreeNode(element);
        int position = mp[element];
        
        root->right = buildTree(inorder, postorder, index, position+1, postorderEnd, mp);
        root->left = buildTree(inorder, postorder, index, postorderStart, position-1, mp);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n = inorder.size();
        
        int index = n-1;
        
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[inorder[i]] = i;
        }
        
        TreeNode* root = buildTree(inorder, postorder, index, 0, n-1, mp);
        return root;
    }
};