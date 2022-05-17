/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getNode(TreeNode* cloned, TreeNode* target){
        
        if(cloned == NULL) return NULL;
        
        if(cloned->val == target->val){
            return cloned;
        }
        
        TreeNode* left = getNode(cloned->left, target);
        TreeNode* right = getNode(cloned->right, target);
        
        if(left == NULL){
            return right;
        }
        if(right == NULL){
            return left;
        }
        
        return cloned;
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        return getNode(cloned, target);
    }
};