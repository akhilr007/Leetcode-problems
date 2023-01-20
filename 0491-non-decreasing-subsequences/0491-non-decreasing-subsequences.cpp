class Solution {
public:
    void solve(int idx, vector<int>& nums, vector<vector<int>>& result, vector<int> ds){
        
        if(idx >= nums.size()){
            
            if(ds.size()>1)
                result.push_back(ds);
            return;
        }
        
        if(ds.size() == 0 || nums[idx] >= ds.back()){
            ds.push_back(nums[idx]);
            solve(idx+1, nums, result, ds);
            ds.pop_back();
        }
        
        if(idx > 0 && ds.size() > 0 && nums[idx] == ds.back()){
            return;
        }
        
        solve(idx+1, nums, result, ds);
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        vector<vector<int>> result;
        
        vector<int> ds;
        
        solve(0, nums, result, ds);
        return result;
    }
};