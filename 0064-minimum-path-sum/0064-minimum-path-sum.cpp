class Solution {
public:
    // time complexity ->2^(n+m)
    // space complexity -> O(n+m)
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
        
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return f(n-1, m-1, grid, dp);
    }
};