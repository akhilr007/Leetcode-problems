class Solution {
public:
    int brute(vector<int>& prices)
    {
        int max_profit = 0;
        
        int n = prices.size();
        
        for(int i=0; i<n; i++){
            
            for(int j=i+1; j<n; j++){
                
                if(prices[j] > prices[i]){
                    
                    int curProfit = prices[j] - prices[i];
                    max_profit = max(max_profit, curProfit);
                }
            }
        }
        
        return max_profit;
    }
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        int minPrice = prices[0];
        
        int max_profit = 0;
        
        for(int i=1; i<n; i++){
            
            int curProfit = prices[i] - minPrice;
            max_profit = max(max_profit, curProfit);
            minPrice = min(minPrice, prices[i]);
            
        }
        
        return max_profit;
    }
};