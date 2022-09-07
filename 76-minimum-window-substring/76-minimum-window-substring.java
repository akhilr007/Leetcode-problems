class Solution {
    public String minWindow(String s, String t) {
        
        int count = 0;
        int[] map = new int[256];
        
        for(int i=0; i<t.length(); i++){
            char ch = t.charAt(i);
            if(map[ch] == 0) count++;
            map[ch]++;
        }
        
        int i=0, j=0;
        int res = Integer.MAX_VALUE;
        int start = i;
        
        while(j < s.length()){
            
            char ch = s.charAt(j);
            
            map[ch]--;
            
            if(map[ch] == 0) count--;
            
            if(count == 0){
                
                while(count == 0){
                    
                    if(res > j-i+1){
                        res = j-i+1;
                        start = i;
                    }
                    
                    char c = s.charAt(i);
                    map[c]++;
                    if(map[c] == 1) count++;
                    
                    i++;
                }
            }
            
            j++;
        }
        
        if(res == Integer.MAX_VALUE) return "";
        return s.substring(start, start + res);
    }
}