class Solution {
    public void reverse(int l, int r, int[] nums){
        
        while(l <= r){
            
            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
            
            l++;
            r--;
        }
        
    }
    
    public void swap(int l, int r, int[] nums){
        
        int temp = nums[l];
        nums[l] = nums[r];
        nums[r] = temp;
    }
    
    public void nextPermutation(int[] nums) {
        
        int n = nums.length;
        
        int breakPointIndex=-1;
        for(int index=n-2; index>=0; index--){
            if(nums[index] < nums[index+1]){
                breakPointIndex = index;
                break;
            }
        }
        
        if(breakPointIndex == -1){
            reverse(0, n-1, nums);
            return;
        }
        
        for(int index=n-1; index>breakPointIndex; index--){
            
            if(nums[index] > nums[breakPointIndex]){
                swap(index, breakPointIndex, nums);
                break;
            }
        }
        
        reverse(breakPointIndex+1, n-1, nums);
    }
}