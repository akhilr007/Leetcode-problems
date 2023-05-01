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
    bool isMatch(string s, string p) {
        
        int n = p.size();
        int m = s.size();
        
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(n-1, m-1, s, p, dp);
    }
};