class Solution {
    public int solve(int i, int j, int[][] matrix, int[][] dp){
        
        if(i<0 || j<0 || i>=matrix.length || j>=matrix.length)
            return 1000005;
        
        if(i == matrix.length - 1){
            return matrix[i][j];
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int down = 1000005, downLeft = 1000005, downRight = 1000005;
        if(j>=1)
            downLeft = matrix[i][j] + solve(i+1, j-1, matrix, dp);
        if(j<matrix.length-1)
            downRight = matrix[i][j] + solve(i+1, j+1, matrix, dp);
        down = matrix[i][j] + solve(i+1, j, matrix, dp);
        
        return dp[i][j] = Math.min(downLeft, Math.min(down, downRight));
        
    }
    
    public int minFallingPathSum(int[][] matrix) {
        
        int n = matrix.length;
        
        int[][] dp = new int[n][n];
        for(int[] row: dp)
            Arrays.fill(row, -1);
        
        int ans = 1000005;
        for(int i=0; i<n; i++){
            ans = Math.min(ans, solve(0, i, matrix, dp));
        }
        
        return ans;
    }
}