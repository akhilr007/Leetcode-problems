class Solution {
    public int missingNumber(int[] nums) {
        // [0 ... n]
        
        for(int i=0; i<=nums.length; i++){
            boolean isFound = false;
            
            for(int j=0; j<nums.length; j++){
                
                if(nums[j] == i){
                    isFound = true;
                    break;
                }
            }
            
            if(isFound == false)
                return i;
        }
        
        return -1;
    }
}