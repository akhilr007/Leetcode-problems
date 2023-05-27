class Solution {
    int solve(int index, int[] stones, int[] dp){
        
        if(index >= stones.length)
            return 0;
        
        if(dp[index] != -1)
            return dp[index];
        
        int result = Integer.MIN_VALUE;
        int sum = 0;
        
        for(int i=index; i<index+3 && i<stones.length; i++){
            
            sum += stones[i];
            result = Math.max(result, sum - solve(i+1, stones, dp));
        }
        
        return dp[index] = result;
    }
    
    public String stoneGameIII(int[] stones) {
        
        int n = stones.length;
        
        int[] dp = new int[n];
        Arrays.fill(dp, -1);
        
        int diff = solve(0, stones, dp);
        
        if(diff > 0){
            return "Alice";
        }
        else if(diff < 0){
            return "Bob";
        }
        
        return "Tie";
    }
}