class Solution {
public:
    int solve(int index, int canBuy, int fee, vector<int>& prices, vector<vector<int>>& dp){
        
        if(index >= prices.size())
            return 0;
        
        if(dp[index][canBuy] != -1)
            return dp[index][canBuy];
        
        int profit = 0;
        if(canBuy){
            
            int bought = -prices[index] + solve(index+1, 0, fee, prices, dp);
            int notBought = 0 + solve(index+1, 1, fee, prices, dp);
            
            profit = max(bought, notBought);
        }
        else{
            
            int sold = prices[index] - fee + solve(index+1, 1, fee, prices, dp);
            int notSold = 0 + solve(index+1, 0, fee, prices, dp);
            
            profit = max(sold, notSold);
        }
        
        return dp[index][canBuy] = profit;
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        
        int n = prices.size();
        
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return solve(0, 1, fee, prices, dp);
    }
};