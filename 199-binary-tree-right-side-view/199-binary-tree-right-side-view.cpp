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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> output;
        if(root == NULL) return output;
        
        queue<TreeNode*> q;
        q.push(root);
        
        TreeNode* curr = root;
        
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                
                auto rem = q.front(); q.pop();
                
                if(i == size-1) output.push_back(rem->val);
                
                if(rem->left) q.push(rem->left);
                if(rem->right) q.push(rem->right);
            }
        }
        
        return output;
    }
};