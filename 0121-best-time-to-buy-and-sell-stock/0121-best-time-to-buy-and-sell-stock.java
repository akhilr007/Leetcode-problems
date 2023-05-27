class Solution {
    public int maxProfit(int[] prices) {
        
        int n = prices.length;
        
        int minCost = prices[0];
        int maxProfit = 0;
        
        for(int i=1; i<n; i++){
            
            int curProfit = prices[i] - minCost;
            
            if(curProfit > maxProfit){
                maxProfit = curProfit;
            }
            
            if(prices[i] < minCost){
                minCost = prices[i];
            }
        }
        
        return maxProfit;
    }
}