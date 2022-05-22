class Solution {
public:
    string longestPalindrome(string s) {
        
        int maxi=0;
        int start;
        
        int l, r;
        for(int i=0; i<s.length(); i++){
            l=r=i;
            while(l>=0 and r<s.length() and s[l] == s[r]){
                if(r-l+1 > maxi){
                    start = l;
                    maxi = max(maxi, r-l+1);
                }
                
                l--;
                r++;
            }
            
            l=i;
            r=i+1;
            while(l>=0 and r<s.length() and s[l] == s[r]){
                if(r-l+1 > maxi){
                    start = l;
                    maxi = max(maxi, r-l+1);
                }
                
                l--;
                r++;
            }
        }
        
        return s.substr(start, maxi);
    }
};