class Solution {
public:
    int f(int i, int c, int t, vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target, vector<vector<vector<int>>>& dp){
        
        if(t > target) return 1e8;
        if(i == m){
            return t == target ? 0 : 1e8;
        }
        
        if(dp[i][c][t] != -1) return dp[i][c][t];
        
        int ans = 1e8;
        if(houses[i] == 0){
            
            for(int j=0; j<n; j++){
                ans = min(ans, cost[i][j] + f(i+1, j+1, c == j+1 ? t : t+1, houses,cost, m, n, target, dp));
            }
        }
        else{
            ans = min(ans, f(i+1, houses[i], houses[i] == c ? t : t+1, houses, cost, m, n, target, dp));
        }
        
        return dp[i][c][t] = ans;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>> (n+1, vector<int> (target+1, -1)));
        int ans = f(0, 0, 0, houses, cost, m, n, target, dp);
        return ans == 1e8 ? -1 : ans;
    }
};