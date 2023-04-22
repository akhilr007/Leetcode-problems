class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int i=0;
        return build(preorder, i, INT_MAX);
    }
    
    TreeNode* build(vector<int>& preorder, int& i, int max_bound){
        
        if(i == preorder.size() || preorder[i] > max_bound)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = build(preorder, i, root->val);
        root->right = build(preorder, i, max_bound);
        
        return root;
    }
};