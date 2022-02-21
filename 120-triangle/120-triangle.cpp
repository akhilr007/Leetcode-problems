class Solution {
public:
    
    int f(int i, int j, int n, int m, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        
        if(i==n-1) return triangle[n-1][j];
        if(dp[i][j] != -1) return dp[i][j];
        
        int down = triangle[i][j] + f(i+1, j, n, m, triangle, dp);
        int diagonal = triangle[i][j] + f(i+1, j+1, n, m, triangle, dp);
        
        return dp[i][j] = min(down, diagonal);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n=triangle.size();
        int m=triangle[0].size();
        
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return f(0, 0, n, m, triangle, dp);
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int j=0; j<n; j++){
            dp[n-1][j] = triangle[n-1][j];
        }
        
        for(int i=n-2; i>=0; i--){
            for(int j=i; j>=0; j--){
                
                int down = triangle[i][j] + dp[i+1][j];
                int diagonal = triangle[i][j] + dp[i+1][j+1];
                
                dp[i][j] = min(down, diagonal);
            }
        }
        
        return dp[0][0];
    }
};