class Solution {
public:
    int solve(int index, int canBuy, vector<int>& prices, int n, vector<vector<int>>& dp){

        if(index >= n) return 0;

        if(dp[index][canBuy] != -1)
            return dp[index][canBuy];

        int profit = 0;
        if(canBuy){
            int bought = -prices[index] + solve(index+1, 0, prices, n, dp);
            int notBought = 0 + solve(index+1, 1, prices, n, dp);

            profit = max(bought, notBought);
        }
        else{
            int sold = prices[index] + solve(index+2, 1, prices, n, dp);
            int notSold = 0 + solve(index+1, 0, prices, n, dp);

            profit = max(sold, notSold);
        }

        return dp[index][canBuy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return solve(0, 1, prices, n, dp);
    }
};