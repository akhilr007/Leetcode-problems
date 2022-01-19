class Solution {
public:
    
    int charToInt(char ch){
        return ch-'0';
    }
    
    char intToChar(int num){
        return num + '0';
    }
    
    string addStrings(string s1, string s2) {
        
        
        if(s1.length() < s2.length()){
            swap(s1, s2);
        }
        
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        
        int i=0;
        int j=0;
        int carry=0;
        
        string res="";
        while(i < s1.length()){
            
            int v1 = charToInt(s1[i]);
            int v2=0;
            if(j < s2.length()){
                v2 = charToInt(s2[j]);
            }
            
            int sum = carry + v1 + v2;
            
            res += intToChar(sum%10);
            
            carry = sum/10;
            
            i++;
            j++;
            
        }
        
        if(carry){
            res += intToChar(carry);
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};