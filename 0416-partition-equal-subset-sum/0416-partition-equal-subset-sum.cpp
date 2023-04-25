class Solution {
public:
    bool isSubsetSumK(int index, int target, vector<int>& nums, vector<vector<int>>& dp)
    {
        if(target == 0)
            return true;
        
        if(index == 0)
            return nums[index] == target;
        
        if(dp[index][target] != -1)
            return dp[index][target];
        
        bool not_taken = isSubsetSumK(index-1, target, nums, dp);
        bool taken = false;
        if(nums[index] <= target)
            taken = isSubsetSumK(index-1, target-nums[index], nums, dp);
        
        return dp[index][target] = not_taken || taken;
    }
    
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        
        int total_sum = accumulate(begin(nums), end(nums), 0);
        
        if(total_sum % 2)
            return false;
        
        int target = total_sum / 2;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return isSubsetSumK(n-1, target, nums, dp);
    }
};