class Solution {
public:
    
    const int MOD = (int)1e9 + 7;
    const vector<vector<int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    
    bool isSafe(int row, int col, int m, int n){
        if(row >= 0 && row < m && col >= 0 && col < n)
            return true;
        
        return false;
    }
    
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int result = 1; // each grid is itself an increasing path
        
        for(auto& dir : directions){
            
            int ni = i + dir[0];
            int nj = j + dir[1];
            
            if(isSafe(ni, nj, grid.size(), grid[0].size()) && grid[i][j] > grid[ni][nj]){
                
                result = (result + dfs(ni, nj, grid, dp)) % MOD;
            }
        }
        
        return dp[i][j] = result;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int> (n, -1));
        
        int result = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                
                result = (result + dfs(i, j, grid, dp)) % MOD;
            }
        }
        
        return result;
    }
};