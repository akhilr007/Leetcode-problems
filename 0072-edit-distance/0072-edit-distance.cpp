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
    
    int minDistance(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        
        vector<vector<int>> dp(n+1, vector<int> (m, -1));
        return solve(n-1, m-1, s, t, dp);
    }
};