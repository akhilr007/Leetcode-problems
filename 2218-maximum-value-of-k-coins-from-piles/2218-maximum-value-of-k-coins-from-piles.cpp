class Solution {
public:
    int solve(int i, int k, vector<vector<int>>& piles, vector<vector<int>>& dp){
        
        if(i >= piles.size())
            return 0;
        if(k <= 0)
            return 0;
        if(dp[i][k] != -1)
            return dp[i][k];
        
        int not_taken = solve(i+1, k, piles, dp);
        
        int taken=0;
        int sum=0;
        
        for(int j=0; j<min((int)piles[i].size(), k); j++){
            
            sum += piles[i][j];
            
            taken = max(taken, sum + solve(i+1, k-(j+1), piles, dp));
        }
        
        return dp[i][k] = max(taken, not_taken);
        
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int K) {
        
        int n = piles.size();
        
        vector<vector<int>> dp(n+1, vector<int> (K+1, 0));
        
        for(int i=1; i<=n; i++)
        {
            for(int k=1; k<=K; k++)
            {
                dp[i][k] = dp[i-1][k];
                
                int sum=0;
                int picked = 1;
                for(int val: piles[i-1])
                {
                    if(k - picked < 0)
                        break;
                    
                    sum += val;
                    
                    dp[i][k] = max(dp[i][k], dp[i-1][k-picked] + sum);
                    picked++;
                }
            }
        }
        
        return dp[n][K];
    }
};