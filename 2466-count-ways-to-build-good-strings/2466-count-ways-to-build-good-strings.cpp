class Solution {
public:
    const int mod = (int)1e9+7;
    int solve(int len, int zero, int one, int low, int high,  vector<int>& dp){
        
        if(len > high)
            return 0;
        
        if(dp[len] != -1)
            return dp[len];
        
        int zeroWays = solve(len + zero, zero, one, low, high, dp);
    
        int oneWays = solve(len + one, zero, one, low, high, dp);
        
        int ans = 0;
        if(len >= low && len <= high)
            ans = 1;
        
        return dp[len] = (zeroWays + oneWays + ans) % mod;
        
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        
        int len = 0;
        vector<int> dp(high+1, -1);
        return solve(len, zero, one, low, high, dp);
    }
};