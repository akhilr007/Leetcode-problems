class Solution {
public:
    const int MOD = 1e9+7;
    int solve(int start, string& s, int k, int n, vector<int>& dp){
        
        if(start >= n)
            return 1;
        
        if(dp[start] != -1)
            return dp[start];
        
        if(s[start] == '0')
            return 0;
        
        
        int ans=0;
        
        long num=0;
        
        for(int end=start; end<n; end++){
            
            num = (num*10) + (s[end]-'0');
            if(num > k)
                break;
            
            ans = ((ans % MOD) + (solve(end+1, s, k, n, dp) % MOD))%MOD;
        }
        
        return dp[start] = ans;
    }
    
    int numberOfArrays(string s, int k) {
        
        int n = s.length();
        
        vector<int> dp(n, -1);
        return solve(0, s, k, n, dp);
    }
};