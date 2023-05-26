class Solution {
    public int majorityElement(int[] nums) {
        
        int n = nums.length;
        
        int majorityElement = -1;
        int count = 0;
        
        for(int num: nums){
            
            if(count == 0){
                majorityElement = num;
                count = 1;
            }
            else if(majorityElement == num){
                count++;
            }
            else{
                count--;
            }
        }
        
        count = 0;
        for(int num: nums){
            if(majorityElement == num){
                count++;
            }
        }
        
        if(count > n/2)
            return majorityElement;
        
        return -1;
    }
}