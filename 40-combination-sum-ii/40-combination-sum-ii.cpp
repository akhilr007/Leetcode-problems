class Solution {
public:
    void helper(int i, vector<int>& candidates, int target, vector<int>& ans, vector<vector<int>>& res){
        
        if(target == 0){
            res.push_back(ans);
            return;
        }
        if(target < 0 || i >= candidates.size()) return;
        
        ans.push_back(candidates[i]);
        helper(i+1, candidates, target - candidates[i], ans, res);
        
        ans.pop_back();
        while(i+1 < candidates.size() && candidates[i] == candidates[i+1]) i++;
        
        helper(i+1, candidates, target, ans, res);
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> ans;
        
        helper(0, candidates, target, ans, res);
        return res;
    }
};