class Solution {
public:
    int solve(int i, int j, string& s, string& r, vector<vector<int>>& dp){
        
        if(i<0 || j<0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans=0;
        if(s[i] == r[j])
            ans = 1 + solve(i-1, j-1, s, r, dp);
        else
            ans = max(solve(i-1, j, s, r, dp), solve(i, j-1, s, r, dp));
        
        return dp[i][j] = ans;
    }
    
    int longestPalindromeSubseq(string s) {
        
        int n = s.size();
        string r = s;
        reverse(begin(r), end(r));
        
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(n-1, n-1, s, r, dp);
    }
};