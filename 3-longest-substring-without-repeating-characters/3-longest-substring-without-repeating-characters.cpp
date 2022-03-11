class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int len=0;
        
        
//         for(int i=0; i<s.length(); i++){
//             unordered_map<char, int> mp;
//             for(int j=i; j<s.length(); j++){
                
//                 if(mp.find(s[j]) == mp.end()){
//                     mp[s[j]]++;
//                     len = max(len, j-i+1);
//                 }
//                 else{
//                     break;
//                 }
//             }
//         }
        
//         return len;
        
        int i=0, j=0;
        unordered_map<char, int> mp;
        
        while(j<s.length()){
            
            if(mp.find(s[j]) != mp.end()){
                i = max(i, mp[s[j]] + 1);
            }
            
            mp[s[j]]=j;
            len = max(len, j-i+1);
            j++;
        }
        
        return len;
    }
};