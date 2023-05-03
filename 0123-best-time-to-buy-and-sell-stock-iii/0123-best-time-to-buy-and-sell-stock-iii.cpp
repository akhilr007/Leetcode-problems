class Solution {
public:
    int solve(int index, int canBuy, int cap, vector<int>& prices, int n,
             vector<vector<vector<int>>>& dp){
        
        if(index >= n || cap == 0)
            return 0;
        
        if(dp[index][canBuy][cap] != -1)
            return dp[index][canBuy][cap];
        
        int profit=0;
        if(canBuy){
            int bought = -prices[index] + solve(index+1, 0, cap, prices, n, dp);
            int notBought = 0 + solve(index+1, 1, cap, prices, n, dp);
            
            profit = max(bought, notBought);
        }
        else{
            int sold = prices[index] + solve(index+1, 1, cap-1, prices, n, dp);
            int notSold = 0 + solve(index+1, 0, cap, prices, n, dp);
            
            profit = max(sold, notSold);
        }
        
        return dp[index][canBuy][cap] = profit;
    }
    
    int tabulation(vector<int>& prices){
        
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, 0)));
        
        for(int index=n-1; index>=0; index--){
            
            for(int canBuy=0; canBuy<=1; canBuy++) {
                
                for(int cap=0; cap<=2; cap++){
                    
                    int profit=0;
                    if(canBuy){
                        int bought = -prices[index] + dp[index+1][0][cap];
                        int notBought = 0 + dp[index+1][1][cap];

                        profit = max(bought, notBought);
                    }
                    else{
                        int sold = prices[index] + dp[index+1][1][cap-1];
                        int notSold = 0 + dp[index+1][0][cap];

                        profit = max(sold, notSold);
                    }

                    return dp[index][canBuy][cap] = profit;
                    
                }
                
            }
        }
        
        return dp[0][1][2];
    }
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
        return solve(0, 1, 2, prices, n, dp);
    }
};