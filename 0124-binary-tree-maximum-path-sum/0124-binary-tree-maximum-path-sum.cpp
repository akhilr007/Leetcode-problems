class Solution {
public:
    int dfs(TreeNode* root, int& max_sum){
        
        if(root == NULL)
            return 0;
        
        int left = dfs(root->left, max_sum);
        int right = dfs(root->right, max_sum);
        
        // subtree path with left and right 
        int subtree_with_left_and_right = left + right + root->val;
        
        // subtree path with left or right
        int subtree_with_left_or_right = root->val + max(left, right);
        
        // only root
        int only_root = root->val;
        
        max_sum = max({subtree_with_left_and_right, subtree_with_left_or_right, only_root, max_sum});
        
        // return hum log root ya subtree with left or right kar sakte h kyuki subtree path left and right khud me ek path h jo ki turn ho chuka hai
        return max(only_root, subtree_with_left_or_right);
    }
    
    int maxPathSum(TreeNode* root) {
        
        int max_sum = INT_MIN;
        dfs(root, max_sum);
        return max_sum;
    }
};