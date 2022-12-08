class Solution {
public:
    void findLeafNode(TreeNode* root, vector<int>& v){
        if(root == NULL) return;
        
        if(root->left == NULL && root->right == NULL){
            v.push_back(root->val);
            return;
        }
        
        findLeafNode(root->left, v);
        findLeafNode(root->right, v);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        if(root1 == NULL && root2 == NULL) return true;
        if(root1 == NULL || root2 == NULL) return false;
        
        vector<int> leafOfRoot1, leafOfRoot2;
        findLeafNode(root1, leafOfRoot1);
        findLeafNode(root2, leafOfRoot2);
        
        return leafOfRoot1 == leafOfRoot2;
    }
};