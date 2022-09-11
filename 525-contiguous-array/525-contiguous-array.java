class Solution {
    public int findMaxLength(int[] nums) {
        
        Map<Integer, Integer> map = new HashMap<>();
        int maxlen = 0;
        int sum=0;
        
        map.put(0, -1);
        for(int i=0; i<nums.length; i++){
            if(nums[i]==0) sum += -1;
            else sum += 1;
            
            if(map.containsKey(sum)==true){
                int len = i - map.get(sum);
                maxlen = Math.max(len, maxlen);
            }
            else{
                map.put(sum, i);
            }
        }
        return maxlen;
    }
}