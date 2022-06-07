class Solution {
private:
    int f(int i, int j, string& s, string& t,
         vector<vector<int>>& dp){
        
        if(i<0) return j+1;
        if(j<0) return i+1;
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(s[i] == t[j]){
            return dp[i][j] = f(i-1, j-1, s, t, dp);
        }
        
        int insert = f(i, j-1, s, t, dp);
        int del = f(i-1, j, s, t, dp);
        int replace = f(i-1, j-1, s, t, dp);
        
        return dp[i][j] = 1 + min(insert, min(del, replace));
        
    }
public:
    int minDistance(string s, string t) {
        
        int n = s.length();
        int m = t.length();
        
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return f(n-1, m-1, s, t, dp);
    }
};