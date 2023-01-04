class Solution {
private:
    int solveRec(int n){
        
        if(n == 1 || n == 2) return n;
        
        int oneStep = solveRec(n-1);
        int twoStep = solveRec(n-2);
        
        return oneStep + twoStep;
    }
    
    int solveMem(int n){
        
        if(n == 1 || n == 0) return 1;
        if(t[n] != -1) return t[n];
        
        int oneStep = solveMem(n-1);
        int twoStep = solveMem(n-2);
        
        return t[n] = oneStep + twoStep;
    }
    
    int solveTab(int n){
        
        if(n == 1 or n == 2) return n;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i=3; i<=n; i++){
            
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }
public:
    
    int t[46];
    
    int climbStairs(int n) {
        
        if(n == 1 or n == 2) return n;
        
        int first = 1;
        int second = 2;
        
        for(int i=3; i<=n; i++){
            int temp = first + second;
            first = second;
            second = temp;
        }
        
        return second;
    }
};