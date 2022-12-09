class Solution {
public:
    void solve(TreeNode* root, int pMax, int pMin, int& maxDiff){
        
        if(root == NULL) return;
        
        pMax = max(root->val, pMax);
        pMin = min(root->val, pMin);
        maxDiff = max(maxDiff, abs(pMax - pMin));
        
        solve(root->left, pMax, pMin, maxDiff);
        solve(root->right, pMax, pMin, maxDiff);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        
        int maxDiff=0;
        int pMax = INT_MIN, pMin=INT_MAX;
        solve(root, pMax, pMin, maxDiff);
        return maxDiff;
    }
};