class Solution {
public:
    string reverseWords(string s) {
        
        int i=s.length()-1;
        
        string ans="";
        
        while(i>=0){
            
            while(i>=0 and s[i] == ' ') i--;
            
            if(i<0) break;
            
            int j=i;
            
            while(i>=0 and s[i] != ' ') i--;
            
            if(ans == ""){
                ans += s.substr(i+1, j-i);
            }
            else{
                ans += " " + s.substr(i+1, j-i);
            }
        }
        
        return ans;
    }
};