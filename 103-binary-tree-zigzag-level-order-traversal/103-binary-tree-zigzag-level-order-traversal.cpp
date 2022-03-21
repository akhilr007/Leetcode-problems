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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        if(root == NULL) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int leftToRight = 1;
        
        while(q.size()>0){
            
            int size=q.size();
            vector<int> ans(size);
            
            for(int i=0; i<size; i++){
                
                TreeNode* rem = q.front();
                q.pop();
                
                int index = leftToRight ? i : size - i - 1;
                ans[index] = rem->val;
                
                if(rem->left != NULL) {
                    q.push(rem->left);
                }
                if(rem->right != NULL) {
                    q.push(rem->right);
                }
            }
            
            leftToRight = !leftToRight;
            res.push_back(ans);
        }
        
        return res;
    }
};