class Solution {
public:
    int calculateTotalSum(TreeNode* root){
        
        if(root == NULL) return 0;
        
        int left = calculateTotalSum(root->left);
        int right = calculateTotalSum(root->right);
        
        return root->val + left + right;
    }
    
    int findMaximumProduct(TreeNode* root, long totalSum, long& maxP){
        
        if(root == NULL) return 0;
        
        int left = findMaximumProduct(root->left, totalSum, maxP);
        int right = findMaximumProduct(root->right, totalSum, maxP);
        long subtreeSum = root->val + left + right;
        
        long remainingSubtreeSum = totalSum - subtreeSum;
        maxP = max(maxP, subtreeSum * remainingSubtreeSum);
        
        return subtreeSum;
    }
    
    int maxProduct(TreeNode* root) {
        
        long totalSum = calculateTotalSum(root);
        long maxP = 0;
        
        findMaximumProduct(root, totalSum, maxP);
        
        int MOD = 1e9+7;
        return maxP % MOD;
    }
};