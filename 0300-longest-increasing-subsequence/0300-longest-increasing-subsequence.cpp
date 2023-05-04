class Solution {
public:
    // tc -> O(n*n)
    // sc -> O(n*n) + O(n)
    int solve(int index, int prev_index, vector<int>& nums, vector<vector<int>>& dp){
        
        if(index >= nums.size())
            return 0;
        
        if(dp[index][prev_index+1] != -1)
            return dp[index][prev_index+1];
        
        int notTake = 0 + solve(index+1, prev_index, nums, dp);
        
        int take = 0;
        if(prev_index == -1 || nums[index] > nums[prev_index])
            take = 1 + solve(index+1, index, nums, dp);
        
        return dp[index][prev_index+1] = max(notTake, take);
    }
    
    int tabulation(vector<int>& nums){
        
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        
        for(int index=n-1; index>=0; index--){
            
            for(int prev_index=index-1; prev_index>=-1; prev_index--){
                
                int notTake = 0 + dp[index+1][prev_index+1];
        
                int take = 0;
                if(prev_index == -1 || nums[index] > nums[prev_index])
                    take = 1 + dp[index+1][index+1];

                dp[index][prev_index+1] = max(notTake, take);
            }
        }
        
        return dp[0][0];
        
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return tabulation(nums);
    }
};