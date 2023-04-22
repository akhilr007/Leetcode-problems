class Solution {
public:
    void dfs(TreeNode* root, int k, int& kthElement, int &count){
        
        if(root == NULL)
            return;
        
        dfs(root->left, k, kthElement, count);
        
        count += 1;
        if(count == k){
            kthElement = root->val;
            return;
        }
        
        dfs(root->right, k, kthElement, count);
        
    }
    
    int kthSmallest(TreeNode* root, int k) {
        
        int kthElement = 0;
        int count = 0;
        dfs(root, k, kthElement, count);
        
        return kthElement;
    }
};