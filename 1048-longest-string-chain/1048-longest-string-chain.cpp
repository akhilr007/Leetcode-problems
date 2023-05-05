class Solution {
public:
    bool isStringChain(const string& w1, const string& w2) {
        
        if(w1.size() != w2.size() + 1)
            return false;
        
        int i = 0;
        int j = 0;
        
        while(i<w1.size()){
            
            if(j<w2.size() && w1[i] == w2[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        
        return i == w1.size() && j == w2.size();
    }
    
    int longestStrChain(vector<string>& words) {
        
        int n = words.size();
        
        sort(begin(words), end(words), [](const string& w1, const string& w2) {
            return w1.size() < w2.size();
        } );
        
        vector<int> dp(n, 1);
        int maxi = 0;
        
        for(int index=0; index<n; index++){
            
            for(int prev_index=0; prev_index<index; prev_index++){
                
                if(isStringChain(words[index], words[prev_index])){
                    
                    dp[index] = max(dp[index], 1+dp[prev_index]);
                }
            }
            
            maxi = max(maxi, dp[index]);
        }
        
        return maxi;
    }
};