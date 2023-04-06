class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        
        while(!q.empty()){
            
            int size = q.size();
            vector<int> res(size);
            
            for(int i=0; i<size; i++){
                
                auto node = q.front();
                q.pop();
                
                if(leftToRight){
                    res[i] = node->val;
                }
                else{
                    res[size-1-i] = node->val;
                }
                
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            
            leftToRight = !leftToRight;
            ans.push_back(res);
        }
        
        return ans;
    }
};