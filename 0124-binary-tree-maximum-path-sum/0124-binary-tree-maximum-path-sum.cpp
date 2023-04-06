/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root, int &max_sum){
        
        if(root == NULL)
            return 0;
        
        int left = dfs(root->left, max_sum);
        int right = dfs(root->right, max_sum);
        
        // mujhe neeche hi answer mil gaya [left path, root, right path]
        int subtree_with_left_and_right = left + right + root->val;
        
        // right ya left me se koi ek choose karo kyuki ek me se kisi me -ve val h
        int subtree_with_left_or_right = root->val + max(left, right);
        
        // right and left dono hi -ve h to sirf root pick karo
        int only_root = root->val;
        
        max_sum = max({max_sum, subtree_with_left_and_right, subtree_with_left_or_right, only_root});
        
        // subtree path ko return nai kar sakte kyuki wo ek complete path h aur hum turn ho gaye 
        return max(only_root, subtree_with_left_or_right);
        
    }
    int maxPathSum(TreeNode* root) {
        
        int max_sum = INT_MIN;
        dfs(root, max_sum);
        return max_sum;
    }
};