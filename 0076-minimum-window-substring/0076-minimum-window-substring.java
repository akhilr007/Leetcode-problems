class Solution {
    public String minWindow(String s, String t) {
        
        int[] map = new int[256];
        int count = 0;
        for(int i=0; i<t.length(); i++){
            char ch = t.charAt(i);
            if(map[ch] == 0) count++;
            map[ch]++;
        }
        
        int startIndex=0;
        int minSubstring = Integer.MAX_VALUE;
        
        int i=0;
        int j=0;
        while(j<s.length()){
            
            char ch = s.charAt(j);
            map[ch]--;
            
            if(map[ch] == 0) count--;
            
            if(count == 0){
                
                while(count == 0){
                    
                    int res = j-i+1;
                    if(minSubstring > res){
                        minSubstring = res;
                        startIndex = i;
                    }
                    
                    char c = s.charAt(i);
                    map[c]++;
                    if(map[c] == 1) count++;
                    i++;
                }
            }
            
            j++;
        }
        
        if(minSubstring == Integer.MAX_VALUE) return "";
        return s.substring(startIndex, startIndex+minSubstring);
    }
}