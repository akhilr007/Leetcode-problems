class Solution {
public:
    void solve(vector<int>& nums, vector<int>& temp, vector<int>& ans, vector<vector<int>>& result){
        
        if(ans.size() >= nums.size()){
            result.push_back(ans);
            return;
        }
        
        for(int i=0; i<nums.size(); i++){
            
            if(temp[i] == 0){
                ans.push_back(nums[i]);
                temp[i] = 1;
                solve(nums, temp, ans, result);
                temp[i] = 0;
                ans.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> result;
        vector<int> ans;
        vector<int> temp(nums.size());
        
        solve(nums, temp, ans, result);
        return result;
    }
};