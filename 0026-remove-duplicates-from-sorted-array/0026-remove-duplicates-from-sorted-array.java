class Solution {
    public void swap(int i, int j, int[] nums){
        
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    public int removeDuplicates(int[] nums) {
        
        int i=0, j=i+1;
        for(; j<nums.length;){
            
            if(nums[i] == nums[j]){
                j++;
            }
            else{
                swap(i+1, j, nums);
                i++;
                j++;
            }
        }
        
        return i+1;
        
    }
}