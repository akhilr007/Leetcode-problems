class Solution {
public:
    int mod = 1e9+7;
    /*
    int f(int n, int k, vector<vector<int>>& dp){
        
        if(n == 0) return 0;
        if(k == 0) return 1;
        
        if(dp[n][k] != -1) return dp[n][k];
        
        int inv=0;
        for(int i=0; i<=min(k, n-1); i++){
            inv = (inv + f(n-1, k-i, dp))%mod;
        }
        
        return dp[n][k] = inv;
    }
    
    vector<vector<int>> dp(n+1,vector<int>(k+1, -1));
        return f(n, k, dp);
    }
    */
    int kInversePairs(int n, int k) {
        
        vector<vector<int>> dp(n+1, vector<int>(k+1));
        
        // for(int N=1; N<=n; N++){
        //     for(int K=0; K<=k; K++){
        //         if(K==0){
        //             dp[N][K] = 1;
        //             continue;
        //         }
        //         for(int i=0; i<=min(N-1, K); i++){
        //             dp[N][K] = (dp[N][K] + dp[N-1][K-i])%mod;
        //         }
        //     }
        // }
        
        for(int i=0; i<=n; i++) dp[i][0] = 1;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=k; j++){
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
                if(j>=i){
                    dp[i][j] = (dp[i][j] - dp[i-1][j-i] + mod)%mod;
                }
            }
        }
        
        return dp[n][k];
        
    }
};