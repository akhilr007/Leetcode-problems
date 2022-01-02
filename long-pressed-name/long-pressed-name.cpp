class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        
        // if typed is small then return false
        if(typed.length() < name.length()) return false;
        
        int i=0; // name
        int j=0; // typed
        
        while(j < typed.length()){
            
            if(i < name.length() && name[i] == typed[j]){
                i++;
                j++;
            }
            
            else if(j > 0 && typed[j] == typed[j-1]){
                j++;
            }
            
            else return false;
        }
        
        return i==name.length();
        
    }
};