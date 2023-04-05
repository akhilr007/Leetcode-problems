class Solution {
public:
    int firstUniqChar(string str) {
        
        int freqMap[26] = {0};
        for(auto &s: str){
            freqMap[s-'a']++;
        }
        
        for(int i=0; i<str.length(); i++){
            if(freqMap[str[i]-'a'] == 1){
                return i;
            }
        }
        
        return -1;
    }
};