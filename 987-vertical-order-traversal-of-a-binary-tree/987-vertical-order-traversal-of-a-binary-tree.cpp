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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        
        // hd -> [level, nodes]
        map<int, map<int, multiset<int> > > nodes;
        // node, hd, level
        queue<pair<TreeNode*, pair<int, int> > > q;
        q.push({root, {0, 0} });
        
        while(q.size() > 0){
            
            auto rem = q.front();
            q.pop();
            
            TreeNode* node = rem.first;
            int hd = rem.second.first;
            int lvl = rem.second.second;
            
            nodes[hd][lvl].insert(node->val);
            
            if(node->left != NULL){
                q.push({node->left, {hd-1, lvl+1} });
            }
            if(node->right != NULL){
                q.push({node->right, {hd+1, lvl+1} });
            }
        }
        
        for(auto i : nodes){
            vector<int> res;
            for(auto j : i.second){
                for(auto k : j.second){
                    res.push_back(k);
                }
            }
            ans.push_back(res);
        }
        
        return ans;
    }
};