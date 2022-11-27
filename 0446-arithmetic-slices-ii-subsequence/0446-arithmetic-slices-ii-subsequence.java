class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        
        int n = nums.length;
        Map<Long, Integer>[] maps = new HashMap[n];
        for(int i=0; i<n; i++){
            maps[i] = new HashMap<>();
        }
        
        int result=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                
                long cd = (long)nums[i] - (long)nums[j];
                
                int countAtJ = maps[j].getOrDefault(cd, 0);
                int countAtI = maps[i].getOrDefault(cd, 0);
                
                maps[i].put(cd, countAtI + countAtJ + 1);
                
                result += countAtJ;
            }
        }
        
        return result;
    }
}