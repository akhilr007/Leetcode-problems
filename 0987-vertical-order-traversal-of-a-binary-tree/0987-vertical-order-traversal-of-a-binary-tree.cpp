
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        /*
            for every vertical we have have levels and for every levels we have nodes
        
        */
        map<int, map<int, multiset<int>>> mpp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        // { root , {vertical, level}}
        
        while(!q.empty()){
            
            auto p = q.front();
            q.pop();
            
            auto node = p.first;
            int vertical = p.second.first;
            int level = p.second.second;
            
            mpp[vertical][level].insert(node->val);
            
            if(node->left)
                q.push({node->left, {vertical-1, level+1}});
            if(node->right)
                q.push({node->right, {vertical+1, level+1}});
                
        }
        
        for(auto p: mpp){
            
            vector<int> cols;
            for(auto q: p.second){
                
                multiset<int> nodes = q.second;
                for(auto it: nodes){
                    cols.push_back(it);
                }
            }
            
            ans.push_back(cols);
        }
        
        return ans;
    }
};