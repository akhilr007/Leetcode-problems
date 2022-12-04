class Solution {
    public int minimumAverageDifference(int[] nums) {
        
        int n = nums.length;
        
        long totalSum=0;
        for(int val: nums) totalSum += val;
        
        int minDiff=Integer.MAX_VALUE;
        int minDiffIndex = 0;
        long curSum=0;
        
        for(int i=0; i<n; i++){
            
            curSum += nums[i];
            
            long leftPart = curSum / (i+1);
            long rightPart=0;
            if(i != n-1) rightPart = (totalSum - curSum) / (n-i-1);
            else rightPart = (totalSum - curSum)/1;
            
            int absDiff = (int)Math.abs(leftPart - rightPart);
            if(absDiff < minDiff){
                minDiff = absDiff;
                minDiffIndex = i;
            }
        }
        
        return minDiffIndex;
    }
}