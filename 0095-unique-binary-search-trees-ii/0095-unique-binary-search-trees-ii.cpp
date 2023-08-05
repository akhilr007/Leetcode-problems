
class Solution {
public:
    vector<TreeNode*> solve(int start, int end){
        
        if(start > end){
            return { NULL };
        }
        
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
        
        return result;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        
        return solve(1, n);
    }
};