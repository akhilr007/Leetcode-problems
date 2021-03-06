class Solution {
public:
    
    int f(int ind, vector<int>& coins, int amount, vector<vector<int>>& dp){
        
        if(ind==0){
            if(amount % coins[0]==0) return amount/coins[0];
            else return 1e9;
        }
        
        if(dp[ind][amount] != -1) return dp[ind][amount];
        
        int notTake = 0 + f(ind-1, coins, amount, dp);
        int take = INT_MAX;
        if(coins[ind] <= amount) take = 1 + f(ind, coins, amount-coins[ind], dp);
        
        return dp[ind][amount] = min(notTake, take);
        
    }
    
    
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        
        // vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        // int ans = f(n-1, coins, amount, dp);
        // vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        
        vector<int> prev(amount+1, 0), cur(amount+1, 0);
        
        for(int t=0; t<=amount; t++){
            if(t%coins[0]==0) prev[t] = t/coins[0];
            else prev[t] = 1e9;
        }
        
        for(int i=1; i<n; i++){
            for(int t=0; t<=amount; t++){
                
                int notTake = 0+prev[t];
                int take = INT_MAX;
                if(coins[i] <= t) take = 1 + cur[t-coins[i]];
                
                cur[t] = min(notTake, take);
            }
            prev = cur;
        }
        
        int ans = prev[amount];
        if(ans >= 1e9) return -1;
        return ans;
    }
};