class Solution {
    public boolean isIsomorphic(String s, String t) {
        
        Map<Character, Character> map = new HashMap<>();
        Map<Character, Boolean> used = new HashMap<>();
        
        for(int i=0; i<s.length(); i++){
            
            char sch = s.charAt(i);
            char tch = t.charAt(i);
            
            if(map.containsKey(sch) == true){
                
                if(map.get(sch) != tch) return false;
            }
            else{
                if(used.containsKey(tch) == true){
                    return false;
                }
                else{
                    map.put(sch, tch);
                    used.put(tch, true);
                }
            }
        }
        
        return true;
    }
}