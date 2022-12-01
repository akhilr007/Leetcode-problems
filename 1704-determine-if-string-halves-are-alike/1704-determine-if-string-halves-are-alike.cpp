class Solution {
public:
    bool isVowel(char ch){
        ch = tolower(ch);
        if(ch == 'a' ||ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            return true;
        }
        
        return false;
    }
    
    bool halvesAreAlike(string s) {
        
        int countOfVowelsA = 0, countOfVowelsB=0;
        int length = s.length();
        
        for(int i=0; i<length/2; i++){
            if(isVowel(s[i])) countOfVowelsA++;
        }
        
        for(int i=length/2; i<length; i++){
            if(isVowel(s[i])) countOfVowelsB++;
        }
        
        return countOfVowelsA == countOfVowelsB;
    }
};