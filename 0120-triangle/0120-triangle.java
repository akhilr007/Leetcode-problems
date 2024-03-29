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
        int n = triangle.get(m-1).size();
        
        int[] cur = new int[n];
        int[] front = new int[n];
        
        for(int j=0; j<n; j++){
            front[j] = triangle.get(m-1).get(j);
        }
        
        for(int i=m-2; i>=0; i--){
            
            for(int j=i; j>=0; j--){
                
                int down = triangle.get(i).get(j) + front[j];
                int downRight = triangle.get(i).get(j) + front[j+1];

                cur[j] = Math.min(down, downRight);
            }
            
            front = cur.clone();
        }
        
        return front[0];
    }
}