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
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> res;
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size() > 0){
            
            int size = q.size();
            long sum = 0;
            for(int i=0; i<size; i++){
                
                auto node = q.front();
                q.pop();
                
                sum += node->val;
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            double avg = sum / (size*1.0);
            res.push_back(avg);
        }
        
        return res;
    }
};