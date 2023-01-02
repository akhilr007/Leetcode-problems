class Solution {
public:
    bool detectCapitalUse(string word) {
        
        int n = word.length();
        int countCapitals=0;
        
        bool firstLetter = false;
        if(isupper(word[0])){
            countCapitals++;
            firstLetter=true;
        }
        
        
        for(int i=1; i<n; i++){
            char ch = word[i];
            if(ch >= 'A' && ch <= 'Z') countCapitals++;
            
            if(firstLetter == false && countCapitals > 1) return false;
        }
    
        return (firstLetter == true && countCapitals == 1) ||
            (countCapitals == n) || (countCapitals == 0);
    }
};