class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxi=0;
        
        int minPrice = prices[0];
        
        for(int i=1; i<prices.size(); i++){
            int profit = prices[i] - minPrice;
            maxi = max(maxi, profit);
            minPrice = min(prices[i], minPrice);
        }
        
        return maxi;
    }
};