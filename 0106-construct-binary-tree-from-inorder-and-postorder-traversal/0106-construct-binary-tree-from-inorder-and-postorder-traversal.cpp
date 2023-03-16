class Solution {
public:
    int findIndex(vector<int>& inorder, int element){
        
        for(int i=0; i<inorder.size(); i++){
            if(inorder[i] == element)
                return i;
        }
        
        return -1;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int& index, int start, int end){
        
        if(index<0 || start > end)
            return NULL;
        
        int element = postorder[index--];
        int position = findIndex(inorder, element);
        
        TreeNode* root = new TreeNode(element);
        
        root->right = buildTree(inorder, postorder, index, position+1, end);
        root->left = buildTree(inorder, postorder, index, start, position-1);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n = postorder.size();
        
        int index = n-1;
        
        TreeNode* root = buildTree(inorder, postorder, index, 0, n-1);
        return root;
    }
};