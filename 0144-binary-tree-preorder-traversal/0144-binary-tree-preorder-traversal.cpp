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
    // time complexity -> O(n)
    // space complexity -> O(height of tree) for recursion stack
    void preorderRecursive(TreeNode* root, vector<int>& ans){
        
        if(root == NULL) return;
        
        ans.push_back(root->val);
        preorderRecursive(root->left, ans);
        preorderRecursive(root->right, ans);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> preorder;
        if(root == NULL) return preorder;
        
        stack<TreeNode*> st; // stack imitates recursion
        st.push(root);
        
        while(!st.empty()){
            
            auto node = st.top();
            st.pop();
            
            preorder.push_back(node->val);
            
            if(node->right)
                st.push(node->right);
            if(node->left)
                st.push(node->left);
        }
        return preorder;
    }
};