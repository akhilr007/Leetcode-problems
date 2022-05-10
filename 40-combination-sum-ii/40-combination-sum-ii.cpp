class Solution {
private:
    vector<vector<int>> ans;
public:
    void helper(int i, vector<int>& candidates, vector<int>& combinations, int target, bool pre){
        
        if(target == 0){
            ans.push_back(combinations);
            return;
        }
        // 1 1 2 5 6 7 10
        
        if(target < 0) return;
        
        if(i == candidates.size()) return;
        
        
        // do not pick the element
        helper(i+1, candidates, combinations, target, false);
        if(i>0 && candidates[i] == candidates[i-1] && (!pre)) return;
        
        // pick the element
        combinations.push_back(candidates[i]);
        helper(i+1, candidates, combinations, target - candidates[i], true);
        combinations.pop_back();
        
        
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<int> combinations;
        sort(candidates.begin(), candidates.end());
        helper(0, candidates, combinations, target, false);
        return ans;
    }
};