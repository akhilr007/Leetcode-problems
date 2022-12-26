class Solution {
    // time complexity -> O(n*max(nums[idx]))
    private boolean solve(int idx, int[] nums){
        
        if(idx == nums.length-1){
            return true;
        }
        
        boolean ans = false;
        for(int i=1; i<=nums[idx] && i<nums.length; i++){
            ans = ans | solve(idx + i, nums);
            if(ans == true) break;
         }
        
        return ans;
    }
    
    private boolean solveMem(int idx, int[] nums, int n, int[] dp){
        
        if(idx == n-1){
            return true;
        }
        if(dp[idx] != -1){
            if(dp[idx] == 1) return true;
            else return false;
        }
        
        boolean ans = false;
        for(int i=1; i<=nums[idx] && i<nums.length; i++){
            ans = ans | solveMem(idx + i, nums, n, dp);
            if(ans == true) break;
         }
        
        dp[idx] = ans == true ? 1 : 0;
        return ans;
    }
    
    public boolean canJump(int[] nums) {
        
        int n = nums.length;
        int[] dp = new int[n+1];
        Arrays.fill(dp, -1);
        return solveMem(0, nums, n, dp);
    }
}