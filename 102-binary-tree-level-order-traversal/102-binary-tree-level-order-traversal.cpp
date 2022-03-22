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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        if(root == NULL) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size() > 0){
            
            int size = q.size();
            vector<int> ans;
            
            for(int i=1; i<=size; i++){
                
                TreeNode* rem = q.front();
                q.pop();
                
                ans.push_back(rem->val);
                
                if(rem->left != NULL){
                    q.push(rem->left);
                }
                if(rem->right != NULL){
                    q.push(rem->right);
                }
            }
            res.push_back(ans);
        }
        
        return res;
    }
};