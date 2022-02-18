class Solution {
public:
    int f(int i, vector<int>& dp){
        
        if(i<=1) return 1;
        if(dp[i] != -1) return dp[i];
        
        int oneStep = f(i-1, dp);
        int twoStep = f(i-2, dp);
        
        return dp[i] = oneStep + twoStep;
    
    }
    int climbStairs(int n) {
        
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};