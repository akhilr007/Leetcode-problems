class Solution {
public:
    // time complexity -> 2^n
    int solveRec(int n){
        
        if(n == 1) return 1;
        if(n == 2) return 2;
        
        int oneStep = solveRec(n-1);
        int twoStep = solveRec(n-2);
        
        return oneStep + twoStep;
    }
    
    // time complexity -> O(n) space complexity -> O(n) + O(n) recursion stack space
    int solveMem(int n, vector<int>& dp){
        
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(dp[n] != -1) return dp[n];
        
        int oneStep = solveMem(n-1, dp);
        int twoStep = solveMem(n-2, dp);
        
        return dp[n] = oneStep + twoStep;
    }
    
    int solveTab(int n){
        
        if(n == 1) return 1;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i=3; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }
    
    int climbStairs(int n) {
        
        return solveTab(n);
    }
};