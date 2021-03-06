class Solution {
public:
    int f(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp){
        
        if(ind == prices.size()){
            // you have exceeded the last day
            // you cant sell it 
            // and if you have bought any share now u cant sell it
            return 0;
        }
        
        if(dp[ind][buy] != -1){
            return dp[ind][buy];
        }
        
        int profit=0;
        if(buy){
            // i can buy the share
            // if you bought the share at ith day then price[i] amount will be
            // deducted from your end and you cant buy so you need to sell it in
            // upcoming day
            profit += max((-prices[ind] + f(ind+1, 0, prices, dp)),
                        (0 + f(ind+1, 1, prices, dp)) ) ;
        }
        else{
           profit += max( (prices[ind] + f(ind+1, 1, prices, dp)),
                        (0 + f(ind+1, 0, prices, dp)) ); 
        }
        
        return dp[ind][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        // vector<vector<int>> dp (n, vector<int> (2, -1));
        // return f(0, 1, prices, dp);
        
        // tabulation
        vector<int> ahead(2, 0), cur(2, 0);
        
        // base case
        ahead[0] = ahead[1] = 0;
        
        for(int ind=n-1; ind >= 0; ind--){
            for(int buy=0; buy <= 1; buy++){
                
                int profit = 0;
                
                if(buy){
                    profit += max( (-prices[ind] + ahead[0]),
                                (0 + ahead[1]) ) ;
                }
                else{
                   profit += max( (prices[ind] + ahead[1]),
                                (0 + ahead[0]) ); 
                }
                
                cur[buy] = profit;
            }
            
            ahead = cur;
            
        }
        
        return ahead[1];
    }
};