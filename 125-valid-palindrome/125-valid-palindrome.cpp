class Solution {
public:
    bool isPalindrome(string s) {
        
        string str = "";
        for(auto c : s){
            
            c = tolower(c);
            if(isdigit(c)  or (c >= 'a' && c <= 'z')){
                str += c;
            }
        }
        
        int i=0;
        int j=str.length()-1;
        
        while(i<j){
            if(str[i] != str[j]){
                return false;
            }
            
            i++;
            j--;
        }
        
        return true;
    }
};