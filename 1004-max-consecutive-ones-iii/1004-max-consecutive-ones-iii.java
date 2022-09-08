class Solution {
    public int longestOnes(int[] nums, int k) {
        
        int countZeros=0;
        int maxOnes =0;
        
        int i=0, j=0;
        
        while(j<nums.length){
            
            if(nums[j] == 0) countZeros++;
            
            while(countZeros>k){
                if(nums[i] == 0){
                    countZeros--;
                }
                i++;
            }
            
            maxOnes = Math.max(maxOnes, j-i+1);
            j++;
        }
        
        return maxOnes;
    }
}