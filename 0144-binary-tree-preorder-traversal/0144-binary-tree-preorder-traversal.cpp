class Solution {
public:
    void preorder(TreeNode* root, vector<int>& res){
        
        if(root == NULL)
            return;
        
        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
    }
    
    vector<int> preorderIterative(TreeNode* root){
        
        vector<int> res;
        if(root == NULL)
            return res;
        
        stack<TreeNode*> st;
        
        st.push(root);
        
        while(!st.empty()){
            
            auto node = st.top();
            st.pop();
            
            res.push_back(node->val);
            
            if(node->right)
                st.push(node->right);
            if(node->left)
                st.push(node->left);
        }
        return res;
        
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        
        return preorderIterative(root);
    }
};