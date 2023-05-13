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
    
    int tabulation(int low, int high, int zero, int one){
        
        vector<int> dp(high+1, 0);
        
        for(int len=high; len>=0; len--){
            
            int zeroWays = 0;
            if(len + zero <= high) zeroWays = dp[len + zero];

    
            int oneWays = 0;
            if(len + one <= high) oneWays = dp[len + one];

            int ans = 0;
            if(len >= low && len <= high)
                ans = 1;

            dp[len] = (zeroWays + oneWays + ans) % mod;
        
        }
        
        return dp[0];
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        
        int len = 0;
        vector<int> dp(high+1, -1);
        return tabulation(low, high, zero, one);
    }
};