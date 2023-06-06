class Solution {
    public int subarraySum(int[] nums, int k) {
        
        Map<Integer, Integer> hm = new HashMap<>();
        hm.put(0, 1);
        
        int sum = 0;
        int count = 0;
        
        for(int i=0; i<nums.length; i++){
            
            sum += nums[i];
            
            int remove = sum - k;
            
            if(hm.containsKey(remove) == true){
                count += hm.get(remove);
            }
            
            hm.put(sum, hm.getOrDefault(sum, 0) + 1);
        }
        
        return count;
    }
}