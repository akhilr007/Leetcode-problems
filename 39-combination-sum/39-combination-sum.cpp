class Solution {
public:
    void combinationSum(int ind, int n, int tar, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& res){
        
        if(ind == n){
            
            if(tar == 0){
                
                ans.push_back(res);
            }
            
            return;
        }
        
        // pick the element
        if(candidates[ind] <= tar){
            res.push_back(candidates[ind]);
            combinationSum(ind, n, tar-candidates[ind], candidates, ans, res);
            res.pop_back();
        }
        
        combinationSum(ind+1, n, tar, candidates, ans, res);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        
        vector<int> res;
        
        int n=candidates.size();
        combinationSum(0, n, target, candidates, ans, res);
        
        return ans;
    }
};