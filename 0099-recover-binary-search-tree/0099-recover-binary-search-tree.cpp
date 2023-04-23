class Solution {
public:
    void inorder(TreeNode* root, vector<int>& arr){
        
        if(root == NULL)
            return;
        
        inorder(root->left, arr);
        
        arr.push_back(root->val);
        
        inorder(root->right, arr);
        
    }
    void dfs(TreeNode* root, int& index, vector<int>& arr){
        
        if(root == NULL)
            return;
        
        dfs(root->left, index, arr);
        
        root->val = arr[index++];
        
        dfs(root->right, index, arr);
    }
    void recoverTree(TreeNode* root) {
        
        vector<int> arr;
        inorder(root, arr);
        
        sort(begin(arr), end(arr));
        
        int index = 0;
        dfs(root, index, arr);
    }
};