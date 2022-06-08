class Solution {
public:
    
    bool checkPossible(string& s1, string& s2){
        
        if(s1.size() != s2.size() + 1) return false;
        
        int i=0;
        int j=0;
        
        while(i<s1.size()){
            
            if(s1[i] == s2[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        
        if(i==s1.size() && j==s2.size()) return true;
        
        return false;
    }
    
    static bool comp(string& s1, string& s2){
        return s1.size() < s2.size();
    }
    
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(), words.end(), comp);
        
        int n = words.size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        int maxLength=1;
        
        for(int i=1; i<n; i++){
            int maxi = 0;
            for(int j=0; j<i; j++){
                if(checkPossible(words[i], words[j])){
                    maxi = max(maxi, dp[j]);
                }
            }
            
            dp[i] = maxi+1;
            maxLength = max(dp[i], maxLength);
        }
        
        return maxLength;
    }
};