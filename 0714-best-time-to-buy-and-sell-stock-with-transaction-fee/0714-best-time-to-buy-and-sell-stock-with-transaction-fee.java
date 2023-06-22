class Solution {
    int dfs(int index, int canBuy, int[] prices, int fee, int[][] dp){
        
        if(index >= prices.length)
            return 0;
        
        if(dp[index][canBuy] != -1)
            return dp[index][canBuy];
        
        int profit = 0;
        if(canBuy == 1){
            int bought = -prices[index] + dfs(index+1, 0, prices, fee, dp);
            int notBought = 0 + dfs(index+1, 1, prices, fee, dp);
            
            profit = Math.max(bought, notBought);
        }
        else{
            int sold = prices[index] - fee + dfs(index+1, 1, prices, fee, dp);
            int notSold = 0 + dfs(index+1, 0, prices, fee, dp);
            
            profit = Math.max(sold, notSold);
        }
        
        return dp[index][canBuy] = profit;
    }
    
    public int maxProfit(int[] prices, int fee) {
        
        int[][] dp = new int[prices.length][2];
        for(int[] row: dp)
            Arrays.fill(row, -1);

        return dfs(0, 1, prices, fee, dp);
    }
}