class Solution {
public:
    int solve(int i, int j, string& s, string& t, vector<vector<int>>& dp){
        
        if(i<0)
        {
            // s string is empty -> how many operations do we need to make it t
            // " " -> "it"
            return j+1;
        }
        if(j<0)
        {
            //if t string is empty -> how many operations do we need to make it t
            // "it" -> ""
            return i+1;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == t[j])
            return 0 + solve(i-1, j-1, s, t, dp);
        
        int insert = 1 + solve(i, j-1, s, t, dp);
        int remove = 1 + solve(i-1, j, s, t, dp);
        int replace = 1 + solve(i-1, j-1, s, t, dp);
        
        return dp[i][j] = min({insert, remove, replace});
    }
    
    int tabulation(string s, string t){
        
        int n = s.size();
        int m = t.size();
        
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
        // if(i<0) return j+1
        for(int j=0; j<=m; j++)
            dp[0][j] = j;
        
        // if(j<0) return i+1
        for(int i=0; i<=n; i++)
            dp[i][0] = i;
        
        for(int i=1; i<=n; i++){
            
            for(int j=1; j<=m; j++){
                
                if(s[i-1] == t[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                    continue;
                }
                    
                int insert = 1 + dp[i][j-1];
                int remove = 1 + dp[i-1][j];
                int replace = 1 + dp[i-1][j-1];
                
                dp[i][j] = min({insert, remove, replace});
            }
        }
        
        return dp[n][m];
        
    }
    
    int minDistance(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return tabulation(s, t);
    }
};