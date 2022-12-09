class Solution {
public:
    int solve(TreeNode* root, int pMax, int pMin){
        
        if(root == NULL) return abs(pMax - pMin);
        
        pMax = max(root->val, pMax);
        pMin = min(root->val, pMin);
        
        int left = solve(root->left, pMax, pMin);
        int right = solve(root->right, pMax, pMin);
        
        return max(left, right);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        
        int pMax = INT_MIN, pMin=INT_MAX;
        return solve(root, pMax, pMin);
    }
};