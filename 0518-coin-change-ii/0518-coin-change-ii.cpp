class Solution {
public:
    int solve(int index, int amount, vector<int>& coins, vector<vector<int>>& dp){
        
        
        if(index == 0)
            return amount % coins[index]==0;
        
        if(dp[index][amount] != -1)
            return dp[index][amount];
        
        int notTaken = solve(index-1, amount, coins, dp);
        
        int taken=0;
        if(coins[index] <= amount){
            taken = solve(index, amount-coins[index], coins, dp);
        }
        
        return dp[index][amount] = taken + notTaken;
    }
    
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        return solve(n-1, amount, coins, dp);
        
    }
};