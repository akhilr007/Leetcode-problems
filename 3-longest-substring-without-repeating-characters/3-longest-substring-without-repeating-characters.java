class Solution {
    public int lengthOfLongestSubstring(String s) {
        
        HashSet<Character> set = new HashSet<>();
        
        int l=0;
        int res = 0;
        
        for(int r=0; r<s.length(); r++){
            
            char ch = s.charAt(r);
            while(set.contains(ch) == true){
                char c = s.charAt(l);
                set.remove(c);
                l++;
            }
            
            set.add(ch);
            res = Math.max(res, r-l+1);
        }
        
        return res;
    }
}