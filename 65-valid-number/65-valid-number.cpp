class Solution {
public:
    bool isNumber(string s) {
        
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