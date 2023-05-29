class Solution {
    public int subarraySum(int[] nums, int k) {
        
        HashMap<Integer, Integer> map = new HashMap<>();
        
        map.put(0, 1);
        
        int count = 0;
        int preSum = 0;
        
        for(int num: nums){
            
            preSum += num;
            int remove = preSum - k;
            
            count += map.getOrDefault(remove, 0);
            map.put(preSum, map.getOrDefault(preSum, 0) + 1);
        }
        
        return count;
    }
}