class Solution {
public:
    
    bool f(int idx, vector<int>& nums, int tar, vector<vector<int>>& dp){
        
        if(tar==0) return true;
        if(idx==0) return nums[idx] == tar;
        
        if(dp[idx][tar] != -1) return dp[idx][tar];
        
        bool notTake = f(idx-1, nums, tar, dp);
        bool take = false;
        if(nums[idx] <= tar) take = f(idx-1, nums, tar-nums[idx], dp);
        
        return dp[idx][tar] = notTake | take;
    }
    
    bool canPartition(vector<int>& nums) {
        
        int n=nums.size();
        
        int totalSum=0;
        for(auto val : nums) totalSum += val;
        
        if(totalSum%2) return false;
        
        int tar = totalSum/2;
        
        vector<vector<int>> dp(n, vector<int> (tar+1, -1));
        return f(n-1, nums, tar, dp);
    }
};