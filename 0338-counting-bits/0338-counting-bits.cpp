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
        
        vector<int> result(n+1, 0);
        
        vector<int> dp(n+1, -1);
        
        for(int index=0; index<=n; index++){
            result[index] = solve(index, dp);
        }
        return result;
    }
};