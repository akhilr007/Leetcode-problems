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
    void getNodes(TreeNode* root, vector<TreeNode*>& nodes){
        
        if(root == NULL) return;
        
        getNodes(root->left, nodes);
        nodes.push_back(root);
        getNodes(root->right, nodes);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        
        if(root == NULL) return NULL;
        
        vector<TreeNode*> nodes;
        getNodes(root, nodes);
        
        root = nodes[0];
        TreeNode* temp = root;
        for(int i=1; i<nodes.size(); i++){
            temp->left = NULL;
            temp->right = nodes[i];
            temp=temp->right;
        }
        
        temp->left = NULL;
        temp->right = NULL;
        
        return root;
    }
};