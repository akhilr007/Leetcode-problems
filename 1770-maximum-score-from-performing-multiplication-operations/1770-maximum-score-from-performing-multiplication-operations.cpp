class Solution {
public:
    int f(int i, int s, vector<int>& nums, vector<int>& multipliers, vector<vector<int>>& dp){
        
        if(i>=multipliers.size()) return 0;
        
        if(dp[i][s] != INT_MIN) return dp[i][s];
        
        int e = nums.size()-(i-s)-1;
        int start = (multipliers[i] * nums[s]) + f(i+1, s+1, nums, multipliers, dp);
        int end = (multipliers[i] * nums[e]) + f(i+1, s, nums, multipliers, dp);
        
        return dp[i][s] = max(start, end);
       
        
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        
        vector<vector<int>> dp(1001, vector<int> (1001, INT_MIN));
        return f(0, 0, nums, multipliers, dp);
    }
};