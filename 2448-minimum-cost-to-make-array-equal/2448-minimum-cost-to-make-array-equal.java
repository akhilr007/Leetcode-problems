class Solution {
    public long findCost(int[] nums, int[] cost, int target){
        
        long result = 0;
        
        for(int i=0; i<nums.length; i++){
            
            result += (long)(Math.abs(nums[i] - target)) * cost[i];
        }
        
        return result;
    }
    
    public long minCost(int[] nums, int[] cost) {
        
        long result = Integer.MAX_VALUE;
        
        int left = Integer.MAX_VALUE;
        int right = Integer.MIN_VALUE;
        
        for(int i=0; i<nums.length; i++){
            if(nums[i]<left)
                left = nums[i];
            if(nums[i]>right)
                right=nums[i];
        }
        
        while(left <= right){
            
            int mid = left + (right - left) / 2;
            
            long cost1 = findCost(nums, cost, mid);
            long cost2 = findCost(nums, cost, mid+1);
            
            result = Math.min(cost1, cost2);
            
            if(cost2 > cost1){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        
        return result == Integer.MAX_VALUE ? 0 : result;
    }
}