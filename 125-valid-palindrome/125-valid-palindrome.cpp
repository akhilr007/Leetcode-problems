class Solution {
public:
    bool alphaNum(char c){
        
        if ( (c >= 'A' and c <= 'Z') ||
             (c >= 'a' and c <= 'z') ||
             (c >= '0' and c <= '9')){
            return true;
        }
        return false;
    }
    
    bool isPalindrome(string s) {
        
        int l=0;
        int r=s.length()-1;
        
        while(l<r){
            
            while(l<r and alphaNum(s[l])==false) l++;
            while(l<r and alphaNum(s[r])==false) r--;
            
            if(tolower(s[l]) != tolower(s[r])) return false;
            l++;
            r--;
        }
        
        return true;
    }
};