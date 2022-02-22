class Solution {
public:
    
    bool f(int idx, int target, vector<int>& nums, vector<vector<int>>& dp){
        
        if(target == 0) return true;
        if(idx==0) return nums[idx] == target;
        
        if(dp[idx][target] != -1) return dp[idx][target];
        
        bool notTake = f(idx-1, target, nums, dp);
        bool take = false;
        
        if(nums[idx]<=target) take = f(idx-1, target-nums[idx], nums, dp);
        
        return dp[idx][target] = notTake|take;
    }
    
    bool canPartition(vector<int>& nums) {
        
        int n=nums.size();
        
        int totalSum=0;
        for(auto val: nums) totalSum += val;
        
        if(totalSum%2) return false;
        
        int target = totalSum/2;
        
        vector<vector<int>> dp(n, vector<int> (target+1, -1));
        return f(n-1, target, nums, dp);
    }
};