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
    void helper(TreeNode* root, vector<int> digitCount, int& ans){
        
        if(root == NULL) return;
        if(root->left==NULL && root->right==NULL){
            // cout<<"root: "<<root->val<<" ";
            int oddCount=0;
            digitCount[root->val]++;
            for(int i=1; i<digitCount.size(); i++){
                if(digitCount[i]%2) oddCount++;
                // cout<<i<<"-> "<<digitCount[i]<<" ";
            }
            // cout<<endl;
            
            if(oddCount>1) return;
            ans++;
            return;
        }
        
        digitCount[root->val]++;
        
        helper(root->left, digitCount, ans);
        helper(root->right, digitCount, ans);
        
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        
        vector<int> digitCount(10, 0);
        int ans=0;
        helper(root, digitCount, ans);
        return ans;
    }
};