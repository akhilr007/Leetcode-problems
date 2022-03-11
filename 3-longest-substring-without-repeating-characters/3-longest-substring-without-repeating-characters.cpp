class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int len=0;
        
        
        for(int i=0; i<s.length(); i++){
            unordered_map<char, int> mp;
            for(int j=i; j<s.length(); j++){
                
                if(mp.find(s[j]) == mp.end()){
                    mp[s[j]]++;
                    len = max(len, j-i+1);
                }
                else{
                    break;
                }
            }
        }
        
        return len;
    }
};