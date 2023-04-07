
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = preorder.size();
        
        map<int, int> mpp;
        for(int i=0; i<n; i++)
            mpp[inorder[i]] = i;
        
        TreeNode* root = buildTree(preorder, 0, n-1, inorder, 0, n-1, mpp);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder,int inStart, int inEnd, map<int, int>& mpp){
        
        if(preStart > preEnd or inStart > inEnd)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        int inRoot = mpp[root->val]; // index position
        int nums_on_left = inRoot - inStart;
        
        root->left = buildTree(preorder, preStart+1, preStart+nums_on_left, inorder, inStart, inRoot-1, mpp);
        root->right = buildTree(preorder, preStart+nums_on_left+1, preEnd, inorder, inRoot+1, inEnd, mpp);
        
        return root;
    }
};