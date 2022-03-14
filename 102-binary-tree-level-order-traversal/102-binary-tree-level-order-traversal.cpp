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
        
        vector<vector<int>> ans;
        
        if(root == NULL) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size() > 0){
            
            int count = q.size();
            vector<int> res;
            
            for(int i=0; i<count; i++){
                
                TreeNode* rem = q.front();
                q.pop();
                
                res.push_back(rem->val);
                
                if(rem->left != NULL) q.push(rem->left);
                if(rem->right != NULL) q.push(rem->right);
            }
            
            ans.push_back(res);
        }
        
        return ans;
    }
};