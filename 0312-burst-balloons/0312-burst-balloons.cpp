class Solution {
public:
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        
        if(i>j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int maxi = 0;
        for(int ind=i; ind<=j; ind++){
            
            int c1 = i-1>=0 ? nums[i-1] : 1;
            int c2 = j+1<nums.size() ? nums[j+1] : 1;
            
            int cost = (c1 * c2 * nums[ind]) + solve(i, ind-1, nums, dp) + solve(ind+1, j, nums, dp);
            maxi = max(cost, maxi);
        }
        
        return dp[i][j] = maxi;
    }
    
    int maxCoins(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(0, n-1, nums, dp);
    }
};