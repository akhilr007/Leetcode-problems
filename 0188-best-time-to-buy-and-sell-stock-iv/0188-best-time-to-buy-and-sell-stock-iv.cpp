class Solution {
public:
    int solve(int index, int transactionNo, int k, vector<int>& prices,
             vector<vector<int>>& dp){
        
        if(index >= prices.size() || transactionNo == 2*k)
            return 0;
        
        if(dp[index][transactionNo] != -1)
            return dp[index][transactionNo];
        
        int profit = 0;
        if(transactionNo % 2 == 0){
            // buy
            int bought = -prices[index] + solve(index+1, transactionNo+1, k, prices, dp);
            int notBought = 0 + solve(index+1, transactionNo, k, prices, dp);
            
            profit = max(bought, notBought);
        }
        else{
            // sell
            int sold = prices[index] + solve(index+1, transactionNo+1, k, prices, dp);
            int notSold = 0 + solve(index+1, transactionNo, k, prices, dp);
            
            profit = max(sold, notSold);
        }
        
        return dp[index][transactionNo] = profit;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        
        vector<vector<int>> dp(n, vector<int>(2*k, -1));
        return solve(0, 0, k, prices, dp);
    }
};