class Solution {
public:
    bool getPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& result){

        if(root == NULL)
            return false;
        
        result.push_back(root);
        
        if(root == target)
            return true;

        bool left = getPath(root->left, target, result);
        if(left == true) return true;

        bool right = getPath(root->right, target, result);
        if(right == true) return true;

        result.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == NULL)
            return NULL;

        if(root == p || root == q)
            return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left == NULL)
            return right;
        else if(right == NULL)
            return left;
        else
            return root;
    }
};