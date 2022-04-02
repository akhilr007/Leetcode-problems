class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxProfit=0;
        
        // maintain min price of the stock and calculate profit
        // we bought the stock at day 1
        int mini = prices[0];
        
        // so we can sell from day 2 if we get profit
        for(int i=1; i<prices.size(); i++){
            
            int profit = prices[i] - mini;
            maxProfit = max(profit, maxProfit);
            //maintain min
            mini = min(mini, prices[i]);
        }
        
        return maxProfit;
    }
};