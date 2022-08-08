class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n, 1);
        int lis = 0;
        
        for(int ind=0; ind<n; ind++){
            for(int prev_ind=0; prev_ind<ind; prev_ind++){
                if(nums[prev_ind] < nums[ind])
                    dp[ind] = max(dp[ind], 1 + dp[prev_ind]);
            }
            lis = max(lis, dp[ind]);
        }
        return lis;
    }
};