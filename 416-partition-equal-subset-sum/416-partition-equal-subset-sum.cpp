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
        
        vector<vector<bool>> dp(n, vector<bool> (tar+1, false));
        //return f(n-1, nums, tar, dp);
        
        // for target -> 0 
        for(int i=0; i<n; i++) dp[i][0] = true;
        if(nums[0] <= tar) dp[0][nums[0]] = true;
        
        
        for(int i=1; i<n; i++){
            for(int t=1; t<=tar; t++){
                
                bool notTake = dp[i-1][t];
                bool take = false;
                if(nums[i] <= t) take = dp[i-1][t-nums[i]];
                
                dp[i][t] = notTake | take;
            }
        }
        
        return dp[n-1][tar];
        
    }
};