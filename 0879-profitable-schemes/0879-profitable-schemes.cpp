class Solution {
public:
    int MOD = 1e9+7;
    
    int solve(int i, int p, int n, vector<int>& group, vector<int>& profit, int minProfit,
             vector<vector<vector<int>>>& dp){
        
        if(i >= group.size()){
            if(p >= minProfit)
                return 1;
            else
                return 0;
        }
        
        if(dp[i][p][n] != -1)
            return dp[i][p][n];
        
        int notTaken = solve(i+1, p, n, group, profit, minProfit, dp);
        int taken=0;
        if(n - group[i] >= 0)
            taken += solve(i+1, p+profit[i], n-group[i], group, profit, minProfit, dp);
        
        return dp[i][p][n] =  (notTaken + taken) % MOD;
    }
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        
        int size = profit.size();
        int sum = accumulate(begin(profit), end(profit), 0);
        
        vector<vector<vector<int>>> dp(size+1, vector<vector<int>> (sum+1, vector<int> (n+1, -1)));
        return solve(0, 0, n, group, profit, minProfit, dp);
    }
};