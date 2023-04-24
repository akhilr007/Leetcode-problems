class Solution {
    public int solve(int i, int j, int[][] grid, int[][] dp){
        
        if(i<0 || j<0)
            return 1000005;
        
        if(i == 0 && j == 0)
            return grid[i][j];
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int up = grid[i][j] + solve(i-1, j, grid, dp);
        int left = grid[i][j] + solve(i, j-1, grid, dp);
        
        return dp[i][j] = Math.min(up, left);
    }
    
    public int minPathSum(int[][] grid) {
        
        int m = grid.length;
        int n = grid[0].length;
        
        int[] prev = new int[n];
        int[] cur = new int[n];
        
        for(int i=0; i<m; i++){
            
            for(int j=0; j<n; j++){
                
                if(i == 0 && j == 0){
                    cur[j] = grid[i][j];
                    continue;
                }
                
                int up = 1000005, left = 1000005;
                if(i>=1) up = grid[i][j] + prev[j];
                if(j>=1) left = grid[i][j] + cur[j-1];
                
                cur[j] = Math.min(up, left);
            }
            prev = cur;
        }
        
        return prev[n-1];
    }
}