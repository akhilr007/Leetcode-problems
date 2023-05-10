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
        
        if(n == 0) return {0};
       
        vector<int> dp(n+1, 0);
        
        dp[0] = 0;
        dp[1] = 1;
        
        for(int index=2; index<=n; index++){
            
            int n = index;
            if(n % 2 == 0)
                dp[n] = dp[n/2];
            else
                dp[n] = 1 + dp[n/2];
        }
        
        return dp;
    }
};