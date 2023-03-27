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
    
    // time complexity -> O(n*m)
    // space complexity -> O(n*m)
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> cur(m, 0), prev(m, 0);
        
        // base case
        for(int i=0; i<n; i++){
            
            for(int j=0; j<m; j++){
                
                if(i == 0 and j == 0){
                    cur[j] = grid[i][j];
                    continue;
                }
                
                int upperPath = 1e8, leftPath = 1e8;
                if(i>0) upperPath = grid[i][j] + prev[j];
                if(j>0) leftPath = grid[i][j] + cur[j-1];
                
                cur[j] = min(upperPath, leftPath);
            }
            
            prev = cur;
            
        }
        
        return prev[m-1];
    }
};