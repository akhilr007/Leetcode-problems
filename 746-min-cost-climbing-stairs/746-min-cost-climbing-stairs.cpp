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
        //vector<int> dp(n, 0);
        int prev1 = cost[1];
        int prev2 = cost[0];
       // return min(f(n-1, cost, dp), f(n-2, cost, dp));
        
        for(int i=2; i<n; i++){
            
            int fs = cost[i] + prev1;
            int ss = cost[i] + prev2;

            int curr = min(fs,ss);
            prev2 = prev1;
            prev1 = curr;

        }
        
        return min(prev1, prev2);
    }
};