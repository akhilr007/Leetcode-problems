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
    
    vector<TreeNode*> targetToRootPath(TreeNode* root, TreeNode* target){
        
        if(root == NULL) return {};
        
        if(root->val == target->val){
            vector<TreeNode*> list;
            list.push_back(root);
            return list;
        }
        
        vector<TreeNode*> lc = targetToRootPath(root->left, target);
        if(lc.size() > 0){
            lc.push_back(root);
            return lc;
        }
        
        vector<TreeNode*> rc = targetToRootPath(root->right, target);
        if(rc.size() > 0){
            rc.push_back(root);
            return rc;
        }
        
        return {};
    }
    
    void printKLevelDown(TreeNode* node, int k, TreeNode* prbht, vector<int>& res){
        
        if(node == NULL || node == prbht) return;
        
        if(k==0){
            res.push_back(node->val);
            return;
        }
        
        printKLevelDown(node->left, k-1, prbht, res);
        printKLevelDown(node->right, k-1, prbht, res);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        // find target to root path
        vector<TreeNode*> path = targetToRootPath(root, target);
        vector<int> res;
        TreeNode* prbht = NULL;
        
        for(int i=0; i<path.size(); i++){
            
            TreeNode* node = path[i];
            printKLevelDown(node, k-i, prbht, res);
            prbht = node;
        }
        
        return res;
    }
};