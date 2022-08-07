class Solution {
public:
    int countVowelPermutation(int n) {
        
        vector<vector<long>> dp(5, vector<long>(n+1, 0));
        for(int i=0; i<5; i++){
            dp[i][1] = 1;
        }
        
        int a=0, e=1, i=2, o=3, u=4;
        long mod = 1e9+7;
        
        for(int j=2; j<=n; j++){
            dp[a][j] = ((dp[e][j-1]%mod) + (dp[i][j-1]%mod) + (dp[u][j-1]%mod) % mod);
            dp[e][j] = ((dp[a][j-1]%mod) + (dp[i][j-1]%mod) % mod);
            dp[i][j] = ((dp[e][j-1]%mod) + (dp[o][j-1]%mod ) % mod);
            dp[o][j] = dp[i][j-1] % mod;
            dp[u][j] = ((dp[i][j-1]%mod) + (dp[o][j-1]%mod)% mod);
        }
        
        long sum=0;
        for(int j=0; j<5; j++){
            sum += dp[j][n];
        }
        
        sum = sum % mod;
        return (int)sum;
    }
};