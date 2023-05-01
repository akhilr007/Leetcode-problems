class Solution {
public:
    bool solve(int i, int j, string& s, string& p, vector<vector<int>> & dp){
        
        if(i < 0 && j < 0) return true;
        if(i<0 && j >= 0) return false;
        if(j<0 && i >= 0){
            
            for(int ii=0; ii<=i; ii++){
                if(p[ii] != '*')
                    return false;
            }
            
            return true;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(p[i] == s[j] || p[i] == '?')
            return dp[i][j] = solve(i-1, j-1, s, p, dp);
        
        if(p[i] == '*')
            return dp[i][j] = solve(i-1, j, s, p, dp) || solve(i, j-1, s, p, dp);
        
        
        return dp[i][j] = false;
    }
    
    bool tabulation(string& p, string& s){
        
        int n = p.size();
        int m = s.size();
        
        vector<vector<bool>> dp(n+1, vector<bool> (m+1, false));
        
        // if(i<0 and j<0) return true;
        dp[0][0] = true;
        
        // if(i<0 && j>=0) return false;
        for(int j=1; j<=m; j++)
            dp[0][j] = false;
        
        /* if(j<0 && i>=0){
                for(int ii = 1; ii<=i; ii++)
                    if(p[ii] != '*') return false;
                    
                return true;
            }
        */
        for(int i=1; i<=n; i++){
            
            bool flag = true;
            for(int ii=1; ii<=i; ii++){
                if(p[ii-1] != '*'){
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }
        
        for(int i=1; i<=n; i++){
            
            for(int j=1; j<=m; j++) {
                
                if(p[i-1] == s[j-1] || p[i-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[i-1] == '*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else{
                    dp[i][j] = false;
                }
            }
        }
        
        return dp[n][m];
    
    }
    
    bool isMatch(string s, string p) {
        
        int n = p.size();
        int m = s.size();
        
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return tabulation(p, s);
    }
};