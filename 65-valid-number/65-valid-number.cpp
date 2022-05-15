class Solution {
public:
    bool isNumber(string s) {
        
        /*
        -ve cases:
        1. decimal point after decimal seen in the past
        2. decimal point after the power valur .i.e, after e
        3. e again after e seen in the past
        4. e without a prefixed number
        5. +/- will only occur at index 0 or index e+1
        6. see any other char other than 0-9+-eE.
        */
        
        if(s.length()==0) return false;
        
        bool numberSeen = false;
        bool decimalSeen = false;
        bool eSeen = false;
        
        for(int i=0; i<s.length(); i++){
            char c = s[i];
            switch(c){
                case '.':
                    if(decimalSeen || eSeen) return false;
                    decimalSeen = true;
                    break;
                case 'E':
                case 'e':
                    if(eSeen || !numberSeen) return false;
                    eSeen = true;
                    numberSeen = false;
                    break;
                case '+':
                case '-':
                    if(i != 0 && s[i-1] != 'e') return false;
                    numberSeen = false;
                    break;
                default:
                    if(!isdigit(c)) return false;
                    numberSeen = true;    
            }
        }
        
        return numberSeen;
    }
};