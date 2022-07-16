class Solution {
public:
    int mod = 1e9+7;
    int f(int i, int j, int m, int n, int maxMove, vector<vector<vector<int>>>& dp){
        
        if(maxMove < 0) return 0;
        if(i<0 || j<0 || i>=m || j>=n) return 1;
        
        if(dp[i][j][maxMove] != -1) return dp[i][j][maxMove];
        
        int top = f(i-1, j, m, n, maxMove-1, dp);
        int left = f(i, j-1, m, n, maxMove-1, dp);
        int bottom = f(i+1, j, m, n, maxMove-1, dp);
        int right = f(i, j+1, m, n, maxMove-1, dp);
        
        return dp[i][j][maxMove] = ((top + left ) % mod + (bottom + right)%mod)%mod;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(maxMove+1,-1)));
        return f(startRow, startColumn, m, n, maxMove, dp);
    }
};