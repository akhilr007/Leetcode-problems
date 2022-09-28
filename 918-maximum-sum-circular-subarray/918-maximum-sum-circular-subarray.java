class Solution {
    private int kadane(int[] nums){
        
        int maxSum = nums[0];
        int curSum = 0;
        
        for(int n : nums){
            
            curSum = Math.max(curSum, 0);
            curSum += n;
            maxSum = Math.max(curSum, maxSum);
        }
        
        return maxSum;
    }
    
    public int maxSubarraySumCircular(int[] nums) {
        
        int n = nums.length;
        int maxSum = kadane(nums);
        
        int totalSum = 0;
        for(int i=0; i<nums.length; i++){
            totalSum += nums[i];
            nums[i] *= -1;
        }
        
        int maxSum2 = kadane(nums);
        int maxSumMod = totalSum - (-maxSum2);
        if(maxSumMod == 0) return maxSum;
        return Math.max(maxSum, maxSumMod);
        
    }
}