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
        
        int[] prev = new int[n];
        int[] cur = new int[n];
        
        for(int j=0; j<n; j++)
            prev[j] = matrix[0][j];
        
        for(int i=1; i<n; i++){
            
            for(int j=0; j<n; j++){
                
                int downLeft = 1000005, down=1000005, downRight=1000005;
                if(j>=1) downLeft = matrix[i][j] + prev[j-1];
                if(j+1<n) downRight = matrix[i][j] + prev[j+1];
                down = matrix[i][j] + prev[j];

                cur[j] = Math.min(downLeft, Math.min(down, downRight));
            }
            
            prev = cur.clone();
        }
        
        int ans = 1000005;
        for(int j=0; j<n; j++){
            ans = Math.min(ans, prev[j]);
        }
        
        return ans;
    }
}