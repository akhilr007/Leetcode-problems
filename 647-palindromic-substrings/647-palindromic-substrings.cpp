class Solution {
public:
    int countSubstrings(string s) {
        
        int result = 0;
        int len = s.length();
        
        int l, r;
        for(int i=0; i<len; i++){
            l=r=i;
            while(l>=0 && r<len && s[l] == s[r]){
                result++;
                l--;
                r++;
            }
            
            l=i;
            r=i+1;
            while(l>=0 && r<len && s[l] == s[r]){
                result++;
                l--;
                r++;
            }
        }
        
        return result;
    }
};