class Solution {
public:
    int solve(TreeNode* root, int& maxSum){
        if(root == NULL) return 0;
        
        int left = solve(root->left, maxSum);
        int right = solve(root->right, maxSum);
        
        // neeche hi answer mil gaya
        int subtreePath = root->val + left + right;
        
        // koi ek path left ya right mil gaya
        int singlePath = max(left, right) + root->val;
        
        // left right dono kharab only root acha
        int rootPath = root->val;
        
        maxSum = max({subtreePath, singlePath, rootPath, maxSum});
        
        return max(singlePath, rootPath);
    }
    
    int maxPathSum(TreeNode* root) {
        
        int maxSum=INT_MIN;
        solve(root, maxSum);
        return maxSum;
    }
};