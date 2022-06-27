class Solution {
public:
    int maxCountInMap(unordered_map<char, int>& mp){
        
        int maxi=0;
        for(auto it : mp){
            maxi = max(maxi, it.second);
        }
        
        return maxi;
    }
    
    int characterReplacement(string s, int k) {
        
        unordered_map<char, int> mp;
        int res=0;
        int l=0;
        int maxF=0;
        
        for(int r=0; r<s.length(); r++){
            mp[s[r]]++;
            maxF = max(maxF, mp[s[r]]);
            
            while(r-l+1 - maxF > k){
                mp[s[l]]--;
                l++;
            }
            
            res = max(res, r-l+1);
        }
        
        return res;
    }
};