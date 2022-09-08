class Solution {
    public int lengthOfLongestSubstring(String s) {
        
        Map<Character, Integer> map = new HashMap<>();
        
        int res = 0;
        int i=0, j=0;
        
        while(j < s.length()){
            
            char ch = s.charAt(j);
            map.put(ch, map.getOrDefault(ch, 0) + 1);
            
            if(j-i+1 == map.size()){
                res = Math.max(res, map.size());
                j++;
            }
            
            else if(map.size() < j-i+1){
                
                while(map.size() < j-i+1){
                    
                    char c = s.charAt(i);
                    map.put(c, map.get(c)-1);
                    
                    if(map.get(c) == 0) map.remove(c);
                    i++;
                }
                
                j++;
            }
        }
        
        return res;
    }
}