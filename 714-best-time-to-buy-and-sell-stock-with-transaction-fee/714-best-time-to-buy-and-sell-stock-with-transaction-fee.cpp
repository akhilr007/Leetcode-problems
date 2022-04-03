class Solution {
private:
    int f(int ind, int buy, int fee, vector<int>& prices, vector<vector<int>>& dp){
        
        if(ind == prices.size()) return 0;
        
        if(dp[ind][buy] != -1){
            return dp[ind][buy];
        }
        
        int profit = 0;
        
        if(buy){
            
            profit += max(-prices[ind] + f(ind+1, 0, fee, prices, dp),
                         0 + f(ind+1, 1, fee, prices, dp) );
        }
        else{
            profit += max(prices[ind] - fee + f(ind+1, 1, fee, prices, dp),
                         0 + f(ind+1, 0, fee, prices, dp) );
        }
        
        return dp[ind][buy] = profit;
    }
    
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        int n = prices.size();
        
        vector<int> ahead(2, 0);
        vector<int> cur(2, 0);
        
        //return f(0, 1, fee, prices, dp);
        
        for(int ind=n-1; ind >= 0; ind--){
            for(int buy=0; buy <= 1; buy++){
                
                if(buy){
                    cur[buy] = max(-prices[ind] + ahead[0],
                                      0 + ahead[1]);
                }
                else{
                    cur[buy] = max(prices[ind] - fee + ahead[1],
                                      0 + ahead[0]);
                }
            }
            ahead = cur;
        }
        
        return ahead[1];
    }
};