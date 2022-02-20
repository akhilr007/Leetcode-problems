class Solution {
public:
    
    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        
        if(i<0 || j<0 || grid[i][j] == 1) return 0;
        if(i==0 && j==0) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = f(i-1, j, grid, dp);
        int left = f(i, j-1, grid, dp);
        
        return dp[i][j] = up+left;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        
        // return f(n-1, m-1, grid, dp);
        
        // vector<vector<int>> dp(n, vector<int>(m, 0));
        
        vector<int> prev(m, 0);
        
        for(int i=0; i<n; i++){
            vector<int> cur(m, 0);
            for(int j=0; j<m; j++){
                
                if(grid[i][j] == 1) cur[j] = 0;
                
                else if(i==0 && j==0) cur[j] = 1; 
                
                else{
                    
                    int up = 0;
                    int left =0;
                    
                    if(i>0) up = prev[j];
                    if(j>0) left = cur[j-1];
                    
                    cur[j] = up + left;
                }
            }
            
            prev = cur;
        }
        
        return prev[m-1];
    }
};