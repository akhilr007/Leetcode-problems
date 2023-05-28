class Solution {
    public int longestConsecutive(int[] nums) {
        
        int n = nums.length;
        if(n == 0)
            return 0;
        
        Arrays.sort(nums);
        
        int prev = nums[0];
        int max = 1;
        int cur = 1;
        
        for(int i=1; i<n; i++){
            
            if(nums[i] == prev+1){
                cur++;
            }
            else if(nums[i] != prev){
                cur = 1;
            }
            
            prev = nums[i];
            max = Math.max(max, cur);
        }
        
        return max;
    }
}