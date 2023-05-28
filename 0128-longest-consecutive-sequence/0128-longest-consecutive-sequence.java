class Solution {
    public int longestConsecutive(int[] nums) {
        
        HashSet<Integer> hashset = new HashSet<Integer>();
        for(int num: nums){
            hashset.add(num);
        }
        
        int longestStreak=0;
        for(int num: nums){
            
            if(hashset.contains(num-1) == false){
                
                int curNum = num;
                int curStreak = 1;
                
                while(hashset.contains(curNum+1) == true){
                    
                    curStreak += 1;
                    curNum += 1;
                }
                
                longestStreak = Math.max(longestStreak, curStreak);
            }
        }
        
        return longestStreak;
    }
}