class Solution {
public:
    int solve(int i, int j, string& s1, string& s2, vector<vector<int>>& dp){
        
        if(i < 0 || j < 0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = 0;
        
        if(s1[i] == s2[j])
            ans = 1 + solve(i-1, j-1, s1, s2, dp);
        else
            ans = max(solve(i-1, j, s1, s2, dp), solve(i, j-1, s1, s2, dp));
        
        return dp[i][j] = ans;
    }
    
    int tabulation(string s1, string s2){
        
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
        for(int i=1; i<=n; i++){
            
            for(int j=1; j<=m; j++) {
                
                int ans = 0;
                if(s1[i-1] == s2[j-1])
                    ans = 1 + dp[i-1][j-1];
                else
                    ans = max(dp[i-1][j], dp[i][j-1]);
                
                dp[i][j] = ans;
            }
        }
        
        return dp[n][m];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.size();
        int m = text2.size();
        
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return tabulation(text1, text2);
    }
};