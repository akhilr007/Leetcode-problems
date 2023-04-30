class Solution {
public:
    int solve(int i, int j, string& s, string &t, vector<vector<int>>& dp){
        
        // insert j+1 chars
        if(i<0)
            return j+1;
        //.delete i+1 chars
        if(j<0)
            return i+1;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == t[j]){
            return dp[i][j] = solve(i-1, j-1, s, t, dp);
        }
        
        int insert = solve(i-1, j-1, s, t, dp);
        int remove = solve(i-1, j, s, t, dp);
        int replace = solve(i, j-1, s, t, dp);
        
        return dp[i][j] = 1 + min({insert, remove, replace});
    }
    
    int minDistance(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(n-1, m-1, s, t, dp);
    }
};