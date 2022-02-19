class Solution {
public:
    
    int f(int i, vector<int>& cost, vector<int>& dp){
        
        if(i<0) return 0;
        if(i==0 || i==1) return cost[i];
        
        if(dp[i] != -1) return dp[i];
        
        int fs = cost[i] + f(i-1, cost, dp);
        int ss = cost[i] + f(i-2, cost, dp);
        
        return dp[i] = min(fs, ss);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n=cost.size();
        vector<int> dp(n, 0);
       // return min(f(n-1, cost, dp), f(n-2, cost, dp));
        
        for(int i=0; i<n; i++){
            if(i<2) dp[i] = cost[i];
            else{
                int fs = cost[i] + dp[i-1];
                int ss = cost[i] + dp[i-2];
                dp[i] = min(fs, ss);
            }
        }
        
        return min(dp[n-1], dp[n-2]);
    }
};