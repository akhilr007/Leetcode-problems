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
    
    int solveMem(int n, vector<int>& dp){
        
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(dp[n] != -1) return dp[n];
        
        int oneStep = solveMem(n-1, dp);
        int twoStep = solveMem(n-2, dp);
        
        return dp[n] = oneStep + twoStep;
    }
    
    int climbStairs(int n) {
        
        vector<int> dp(n+1, -1);
        return solveMem(n, dp);
    }
};