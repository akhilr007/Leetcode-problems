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
private:
    int height(TreeNode* root){
        
        if(root == NULL) return 0;
        
        int left = height(root->left);
        int right = height(root->right);
        
        return max(left, right)+1;
    }
    
public:
    int deepestLeavesSum(TreeNode* root) {
        
        int deepestLevel = height(root);
        
        queue<pair<TreeNode*, int>> q;
        int level=1;
        q.push({root, level});
        
        int sum=0;
        
        while(q.size()>0){
            
            int size = q.size();
            for(int i=0; i<size; i++){
                
                auto rem = q.front(); q.pop();
                
                if(rem.second == deepestLevel){
                    sum += rem.first->val;
                }
                
                if(rem.first->left){
                    q.push({rem.first->left, rem.second+1});
                }
                
                if(rem.first->right){
                    q.push({rem.first->right, rem.second+1});
                }
            }
        }
        
        return sum;
    }
};