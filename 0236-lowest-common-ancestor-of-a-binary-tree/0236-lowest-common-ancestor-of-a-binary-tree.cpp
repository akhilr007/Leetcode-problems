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
        
        vector<TreeNode*> rootToNodeP, rootToNodeQ;

        getPath(root, p, rootToNodeP);
        getPath(root, q, rootToNodeQ);

        int n = rootToNodeP.size() , m = rootToNodeQ.size();

        int i;
        for(i=0; i<n && i<m; i++){
            if(rootToNodeP[i]->val != rootToNodeQ[i]->val)
                break;
        }

        return rootToNodeP[i-1];
    }
};