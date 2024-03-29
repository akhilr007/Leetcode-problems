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
    
    int tabulation(int amount, vector<int>& coins){
        
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        
        for(int a=0; a<=amount; a++)
        {
            if(a % coins[0] == 0)
                dp[0][a] = 1;
        }
        
        for(int index=1; index<n; index++){
            for(int a=0; a<=amount; a++){
                
                int notTaken = dp[index-1][a];
        
                int taken=0;
                if(coins[index] <= a){
                    taken = dp[index][a-coins[index]];
                }

                dp[index][a] = taken + notTaken;
            }
        }
        
        return dp[n-1][amount];
    }
    
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        return tabulation(amount, coins);
        
    }
};