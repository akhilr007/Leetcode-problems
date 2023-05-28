class Solution {
    public int solve(int i, int j, int[] temp, int[][] dp){
        
        if(i > j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int result = Integer.MAX_VALUE;
        
        for(int ind=i; ind<=j; ind++){
            
            int cost = temp[j+1] - temp[i-1] + solve(i, ind-1, temp, dp) + solve(ind+1, j, temp, dp);
            result = Math.min(result, cost);
        }
        
        return dp[i][j] = result;
    }
    
    public int tabulation(int[] temp){
        
        int size = temp.length;
        int[][] dp = new int[size][size];
        
        for(int i=size-2; i>=1; i--){
            
            for(int j=1; j<=size-2; j++){
                
                if(i > j)
                    continue;
                
                int result = Integer.MAX_VALUE;
                for(int ind=i; ind<=j; ind++){
                    
                    int cost = temp[j+1] - temp[i-1] + dp[i][ind-1] + dp[ind+1][j];
                    result = Math.min(cost, result);
                }
                
                dp[i][j] = result;
            }
        }
        
        return dp[1][size-2];
    }
    
    public int minCost(int n, int[] cuts) {
        
        int size = cuts.length;
        int[] temp = new int[size+2];
        
        temp[0] = 0;
        temp[temp.length-1] = n;
        
        for(int i=0; i<size; i++){
            temp[i+1] = cuts[i];
        }
        
        Arrays.sort(temp);
        
        int[][] dp = new int[size+2][size+2];
        for(int[] row: dp){
            Arrays.fill(row, -1);
        }
        return tabulation(temp);
    }
}