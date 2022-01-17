class Solution {
public:
    
    bool isVowel(char s){
        
        if(s=='A'||s=='E'||s=='I'||s=='O'||s=='U' || s=='a' || s=='e' || s=='i' || s=='o' || s=='u'){
            return true;
        }
        
        return false;
    }
    string reverseVowels(string s) {
        
        int i=0;
        int j=s.length()-1;
        
        while(i<j){
            
            while(i<j && isVowel(s[i])==false){
                i++;
            }
            
            while(i<j && isVowel(s[j]) == false){
                j--;
            }
            
            swap(s[i], s[j]);
            i++;
            j--;
        }
        
        return s;
        
    }
};