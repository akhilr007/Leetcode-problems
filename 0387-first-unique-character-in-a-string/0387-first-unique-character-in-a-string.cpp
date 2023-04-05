class Solution {
public:
    int firstUniqChar(string str) {
        
        unordered_map<char, int> mpp;
        for(auto &s: str){
            mpp[s]++;
        }
        
        for(int i=0; i<str.length(); i++){
            if(mpp[str[i]] == 1){
                return i;
            }
        }
        
        return -1;
    }
};