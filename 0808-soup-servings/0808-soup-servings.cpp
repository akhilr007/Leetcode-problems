class Solution {
public:
    double solve(int a, int b, vector<vector<double>>& dp){
        
        if(a<=0 and b<=0)
            return 0.5;
        
        if(a <= 0)
            return 1.0;
        
        if(b <= 0)
            return 0.0;
        
        if(dp[a][b] != -1)
            return dp[a][b];
        
        double op1 = solve(a-100, b-0, dp);
        double op2 = solve(a-75, b-25, dp);
        double op3 = solve(a-50, b-50, dp);
        double op4 = solve(a-25, b-75, dp);
        
        return dp[a][b] = 0.25*(op1+op2+op3+op4);
    }
    
    double soupServings(int n) {
        
        if(n >= 4000)
            return 1.0;
        
        vector<vector<double>> dp(n+1, vector<double>(n+1, -1.0));
        return solve(n, n, dp);
    }
};