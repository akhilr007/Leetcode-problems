class Solution {
public:
    bool isPalindrome(string& s){
        
        int i=0;
        int j=s.length()-1;
        
        while(i<j){
            if(s[i] != s[j]) return false;
            
            i++;
            j--;
        }
        
        return true;
    }
    
    int removePalindromeSub(string s) {
        
        if(s.length()==0) return 0;
        
        if(isPalindrome(s)) return 1;
        
        return 2;
    }
};