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
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> postorder;
        if(root == NULL) return postorder;
        
        stack<pair<TreeNode*, int>> st;
        st.push(make_pair(root, 0));
        
        while(st.size()>0){
            
            int state = st.top().second;
            
            if(state == 0){
                // pre 
                st.top().second++;
                
                if(st.top().first->left != NULL){
                    st.push(make_pair(st.top().first->left, 0));
                }
                
            }
            else if(state == 1){
                // in
                st.top().second++;
                
                if(st.top().first->right != NULL){
                    st.push(make_pair(st.top().first->right, 0));
                }
                
            }
            else{
                // post
                postorder.push_back(st.top().first->val);
                st.pop();
            }
        }
        return postorder;
    }
};