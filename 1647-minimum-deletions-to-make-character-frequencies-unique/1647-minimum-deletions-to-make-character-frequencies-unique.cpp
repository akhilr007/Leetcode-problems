class Solution {
public:
    int minDeletions(string s) {
        
        vector<int> v(26, 0);
        for(auto c : s){
            v[c-'a']++;
        }
        
        sort(v.begin(), v.end(), greater<int>());
        
        int maxlen = v[0];
        int ans=0;
        
        for(auto val : v){
            
            if(val > maxlen){
                
                if(maxlen > 0){
                    ans += val - maxlen;
                }
                else{
                    ans += val;
                }
            }
            
            maxlen = min(maxlen-1, val-1);
        }
        
        return ans;
    }
};