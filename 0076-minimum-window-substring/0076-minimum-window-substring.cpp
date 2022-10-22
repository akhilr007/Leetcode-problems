class Solution {
public:
    string minWindow(string s, string t) {
        
        if(s.length() < t.length()) return "";
        
        int map[256] = {0};
        
        int noOfUniqueChars=0;
        for(int i=0; i<t.length(); i++){
            if(map[t[i]] == 0) noOfUniqueChars++;
            map[t[i]]++;
        }
        
        int minSubstringLength=INT_MAX;
        int startIndex=0;
        int i=0, j=0;
        
        while(j<s.length()){
            
            map[s[j]]--;
            if(map[s[j]] == 0) noOfUniqueChars--;
            
            if(noOfUniqueChars == 0){
                
                while(noOfUniqueChars == 0){
                    
                    int curSubstringLength = j-i+1;
                    if(minSubstringLength > curSubstringLength){
                        minSubstringLength = curSubstringLength;
                        startIndex = i;
                    }
                    
                    map[s[i]]++;
                    if(map[s[i]] == 1) noOfUniqueChars++;
                    i++;
                }
            }
            
            j++;
        }
        
        if(minSubstringLength == INT_MAX) return "";
        return s.substr(startIndex, minSubstringLength);
    }
};