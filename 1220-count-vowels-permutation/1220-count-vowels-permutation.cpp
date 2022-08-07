class Solution {
public:
    int countVowelPermutation(int n) {
        
        vector<vector<long>> dp(5, vector<long>(1, 1)), cur(5, vector<long>(1, 0));
        
        int a=0, e=1, i=2, o=3, u=4;
        long mod = 1e9+7;
        
        for(int j=2; j<=n; j++){
            cur[a][0] = ((dp[e][0]%mod) + (dp[i][0]%mod) + (dp[u][0]%mod))%mod;
            cur[e][0] = ((dp[a][0]%mod) + (dp[i][0]%mod))%mod;
            cur[i][0] = ((dp[e][0]%mod) + (dp[o][0]%mod))%mod;
            cur[o][0] = dp[i][0]%mod;
            cur[u][0] = ((dp[i][0]%mod) + (dp[o][0]%mod))%mod;
            dp = cur;
        }
        
        long ans=0;
        for(int j=0; j<5; j++){
            ans += dp[j][0];
        }
        
        ans %= mod;
        return (int)ans;
    }
};