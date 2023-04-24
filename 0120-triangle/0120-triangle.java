class Solution {
    public int solve(int i, int j, List<List<Integer>> triangle, int[][] dp){
        
        if(i == triangle.size() - 1)
            return triangle.get(i).get(j);
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int down = 1000005, downRight = 1000005;
        down = triangle.get(i).get(j) + solve(i+1, j, triangle, dp);
        downRight = triangle.get(i).get(j) + solve(i+1, j+1, triangle, dp);
        
        return dp[i][j] = Math.min(down, downRight);
    }
    
    public int minimumTotal(List<List<Integer>> triangle) {
        
        int m = triangle.size();
        
        int[][] dp = new int[m][m];
        for(int[] row: dp)
            Arrays.fill(row, -1);
        
        return solve(0, 0, triangle, dp);
    }
}