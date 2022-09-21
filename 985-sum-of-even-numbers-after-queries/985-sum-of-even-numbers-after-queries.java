class Solution {
    public int[] sumEvenAfterQueries(int[] nums, int[][] queries) {
        
        int[] ans = new int[nums.length];
        int evenSum=0;
        
        for(int num : nums){
            if(num%2==0) evenSum += num;
        }
        
        int idx=0;
        for(int i=0; i<queries.length; i++){
            int val = queries[i][0];
            int index = queries[i][1];
            
            if(nums[index] % 2 != 0){
                if(val % 2 != 0){
                    evenSum += nums[index] + val;
                }
            }
            else{
                if(val % 2 == 0){
                    evenSum += val;
                }
                else{
                    evenSum -= nums[index];
                }
            }
            nums[index] += val;
            ans[idx++] = evenSum;
            
            
        }
        
        return ans;
    }
}