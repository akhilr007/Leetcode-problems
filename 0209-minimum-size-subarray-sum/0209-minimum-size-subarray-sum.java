class Solution {
    public boolean minSubarraySizeK(int[] nums, int target, int k){
        
        int sum=0;
        
        int i;
        for(i=0; i<k; i++){
            sum += nums[i];
        }
        
        if(sum >= target)
            return true;
        
        int j=0;
        while(i<nums.length){
            
            sum += nums[i] - nums[j];
            i++;
            j++;
            
            if(sum >= target)
                return true;
        }
        
        return false;
    }
    
    public int minSubArrayLen(int target, int[] nums) {
        
        int n = nums.length;
        int ans = n+1;
        
        int low = 1;
        int high = n;
        
        while(low <= high){
            
            int mid = (low + high) >> 1;
            
            if(minSubarraySizeK(nums, target, mid)==true){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid+1;
            }
        }
        
        return ans == n+1 ? 0 : ans;
    }
}