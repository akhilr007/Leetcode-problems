class Solution {
public:
    int solve(int n, vector<int>& dp){
        
        if(n == 0) return 0;
        if(n == 1) return 1;
        
        if(dp[n] != -1)
            return dp[n];
        
        if(n % 2 == 0)
            return dp[n] = solve(n/2, dp);
        
        return dp[n] = 1 + solve(n/2, dp);
    }
    
    vector<int> countBits(int n) {
       
        vector<int> dp(n+1, 0);
        
        dp[0] = 0;
        
        for(int index=1; index<=n; index++){
            
            dp[index] = dp[(index >> 1)] + (index & 1);
        }
        
        return dp;
    }
};