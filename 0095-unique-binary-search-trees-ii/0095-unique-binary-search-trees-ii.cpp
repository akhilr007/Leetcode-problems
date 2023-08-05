
class Solution {
public:
    map<pair<int, int>, vector<TreeNode*>> mp;
    vector<TreeNode*> solve(int start, int end){
        
        if(start > end){
            return { NULL };
        }
        
        if(mp.find({start, end}) != mp.end())
            return mp[{start, end}];
        
        vector<TreeNode*> result;
        
        for(int i=start; i<=end; i++){
            
            vector<TreeNode*> leftBSTs = solve(start, i-1);
            vector<TreeNode*> rightBSTs = solve(i+1, end);
            
            for(auto leftRoot: leftBSTs){
                for(auto rightRoot: rightBSTs){
                    
                    TreeNode* root = new TreeNode(i);
                    
                    root->left = leftRoot;
                    root->right = rightRoot;
                    
                    result.push_back(root);
                }
            }
        }
        
        return mp[{start, end}] = result;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        
        return solve(1, n);
    }
};