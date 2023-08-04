class Solution {
public:
    bool solve(int index, string& s, unordered_set<string>& st, vector<int>& dp){
        
        if(index >= s.size()){
            return true;
        }
        
        if(dp[index] != -1)
            return dp[index];
        
        if(st.find(s) != st.end())
            return true;
        
        for(int l=1; l<=s.size(); l++){
            string str = s.substr(index, l);
            if(st.find(str) != st.end() && solve(index+l, s, st, dp)){
                return dp[index] =  true;
            }
        }
        
        return dp[index] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> st;
        for(auto& word: wordDict){
            st.insert(word);
        }
        
        vector<int> dp(s.length()+1, -1);
        return solve(0, s, st, dp);
    }
};