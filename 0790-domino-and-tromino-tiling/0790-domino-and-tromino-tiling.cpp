class Solution {
public:
    int mod = (int)1e9+7;
    int solve(int n, vector<int>& dp){
        
        if(n == 1 or n == 2) return n;
        if(n == 3) return 5;
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = (2 * solve(n-1, dp) % mod + solve(n-3, dp) % mod) % mod;
    }
    
    int numTilings(int n) {
        
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};