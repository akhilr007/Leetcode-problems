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
    bool isSameTree(TreeNode* p, TreeNode* q){
        
        if(p == NULL and q == NULL) return true;
        if(p == NULL or q == NULL) return false;
        
        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);
        
        bool nodeVal = p->val == q->val;
        
        return left && right && nodeVal;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(root == NULL and subRoot == NULL) return true;
        if(root == NULL or subRoot == NULL) return false;
        
        if(isSameTree(root, subRoot)){
            return true;
        }
        
        bool left = isSubtree(root->left, subRoot);
        bool right = isSubtree(root->right, subRoot);
        
        return left || right;
    }
};