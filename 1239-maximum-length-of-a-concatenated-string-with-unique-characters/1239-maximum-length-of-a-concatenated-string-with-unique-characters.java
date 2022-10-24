class Solution {
    public boolean isOverlap(HashSet<Character> set, String curString){
        
        HashSet<Character> selfCheck = new HashSet<>();
        for(int i=0; i<curString.length(); i++){
            char ch = curString.charAt(i);
            if(selfCheck.contains(ch) == true) return true;
            selfCheck.add(ch);
        }
        
        for(int i=0; i<curString.length(); i++){
            char ch = curString.charAt(i);
            if(set.contains(ch) == true) return true;
        }
        
        return false;
    }
    
    public int helper(int idx, List<String> arr, HashSet<Character> set, int len){
        
        if(idx >= arr.size()){
            return len;
        }
        
        String curString = arr.get(idx);
        if(isOverlap(set, curString) == true){
            return helper(idx+1, arr, set, len);
        }
        else{
            // pick the string
            for(int i=0; i<curString.length(); i++){
                char ch = curString.charAt(i);
                set.add(ch);
            }
            len += curString.length();
            int op1 = helper(idx+1, arr, set, len);
            
            // skip the string
            for(int i=0; i<curString.length(); i++){
                char ch = curString.charAt(i);
                set.remove(ch);
            }
            len -= curString.length();
            int op2 = helper(idx+1, arr, set, len);
            
            return Math.max(op1, op2);
        }
    }
    
    public int maxLength(List<String> arr) {
        
        HashSet<Character> set = new HashSet<>();
        return helper(0, arr, set, 0);
    }
}