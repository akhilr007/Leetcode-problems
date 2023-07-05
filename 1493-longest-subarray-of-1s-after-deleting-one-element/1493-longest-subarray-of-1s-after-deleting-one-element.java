class Solution {
    public int findMax(int[] nums, int skipIndex, int n){
        
        int curLength=0;
        int maxLength=0;
        
        for(int i=0; i<n; i++){
            
            if(i == skipIndex)
                continue;
            
            if(nums[i] == 1){
                curLength++;
                maxLength = Math.max(maxLength, curLength);
            }
            else{
                curLength=0;
            }
        }
        
        return maxLength;
    }
    
    public int longestSubarray(int[] nums) {
        
        int n = nums.length;
        
        int result = 0;
        int countZero = 0;
        
        for(int i=0; i<n; i++){
            
            if(nums[i] == 0){
                
                countZero++;
                result = Math.max(result, findMax(nums, i, n));
            }
        }
        
        if(countZero == 0)
            return n-1;
        
        return result;
    }
}