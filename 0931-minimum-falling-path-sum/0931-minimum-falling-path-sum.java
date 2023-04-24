class Solution {
    public int solve(int i, int j, int[][] matrix, int[][] dp){
        
        if(j<0 || j>=matrix.length)
            return 1000005;
        
        if(i == 0){
            return matrix[i][j];
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int downLeft = matrix[i][j] + solve(i-1, j-1, matrix, dp);
        int downRight = matrix[i][j] + solve(i-1, j+1, matrix, dp);
        int down = matrix[i][j] + solve(i-1, j, matrix, dp);
        
        return dp[i][j] = Math.min(downLeft, Math.min(down, downRight));
        
    }
    
    public int minFallingPathSum(int[][] matrix) {
        
        int n = matrix.length;
        
        int[][] dp = new int[n][n];
        for(int[] row: dp)
            Arrays.fill(row, -1);
        
        int ans = 1000005;
        for(int j=0; j<n; j++){
            ans = Math.min(ans, solve(n-1, j, matrix, dp));
        }
        
        return ans;
    }
}