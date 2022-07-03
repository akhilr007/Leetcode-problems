class Solution {
    public int wiggleMaxLength(int[] nums) {
        if (nums.length < 2) return nums.length;
        
        List<Integer> diff = new ArrayList<>();
        for(int i=1; i<nums.length; i++){
            int val = nums[i] - nums[i-1];
            if(val != 0){
                diff.add(val);
            }
        }
        
        int[]dp = new int[diff.size() + 1];
        int prev = -1;
        
        for(int idx=diff.size()-1; idx>=0; idx--){
            
            int notTake = dp[idx+1];
            
            int take=0;
            if(prev == -1 || (diff.get(idx) >=0 && diff.get(prev) <= 0) || (diff.get(idx) <= 0 && diff.get(prev) >= 0)){
                take = 1 + dp[idx + 1];
                prev = idx;
            }
            
            dp[idx] = Math.max(notTake, take);
        }
        
        return 1 + dp[0];
        
    }
}