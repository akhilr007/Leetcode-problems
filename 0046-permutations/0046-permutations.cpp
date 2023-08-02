class Solution {
public:
    void solve(int index, vector<int>& nums, vector<vector<int>>& result){
        
        if(index >= nums.size()){
            result.push_back(nums);
            return;
        }
        
        for(int i=index; i<nums.size(); i++){
            swap(nums[i], nums[index]);
            solve(index+1, nums, result);
            swap(nums[i], nums[index]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> result;
        
        solve(0, nums, result);
        return result;
    }
};