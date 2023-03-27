class Solution {
public:
    // time complexity ->2^(n+m)
    // space complexity -> O(n+m)
    // for memoization, time complexity -> O(n*m) , space complexity -> O(n*m) + O(n+m)
    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        
        if(i<0 || j<0)
            return 1e8;
        if(i==0 && j==0)
            return grid[i][j];
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int upperPath = grid[i][j] + f(i-1, j, grid, dp);
        int leftPath = grid[i][j] + f(i, j-1, grid, dp);
        
        return dp[i][j] = min(upperPath, leftPath);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(n, vector<int> (m, 0));
        
        // base case
        for(int i=0; i<n; i++){
            
            for(int j=0; j<m; j++){
                
                if(i == 0 and j == 0){
                    dp[i][j] = grid[i][j];
                    continue;
                }
                
                int upperPath = 1e8, leftPath = 1e8;
                if(i>0) upperPath = grid[i][j] + dp[i-1][j];
                if(j>0) leftPath = grid[i][j] + dp[i][j-1];
                
                dp[i][j] = min(upperPath, leftPath);
            }
            
        }
        
        return dp[n-1][m-1];
    }
};