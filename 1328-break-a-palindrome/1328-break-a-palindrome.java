class Solution {
    public String breakPalindrome(String palindrome) {
        
        int n = palindrome.length();
        char[] s = palindrome.toCharArray();
        
        for(int i=0; i<n/2; i++){
            if(s[i] != 'a'){
                s[i] = 'a';
                return String.valueOf(s);
            }
        }
        
        s[n-1] = 'b';
        return n < 2 ? "" : String.valueOf(s);
    }
}