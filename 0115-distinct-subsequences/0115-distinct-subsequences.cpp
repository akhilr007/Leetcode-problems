class Solution {
public:
    int solve(int i, int j, string& s, string& t, vector<vector<int>> & dp){
        
        if(j<0)
            return 1;
        if(i<0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == t[j]){
            // we have two options
            // take (i-1, j-1) and not take = (i-1, j)
            int take = solve(i-1, j-1, s, t, dp);
            int not_take = solve(i-1, j, s, t, dp);
            
            return dp[i][j] = take + not_take;
        }
        
        // if not match
        return dp[i][j] = solve(i-1, j, s, t, dp);
        
    }
    
    int numDistinct(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(n-1, m-1, s, t, dp);
    }
};