class Solution {
public:
    // time complexity -> O(n * l^3)
    bool dfs(string& word, unordered_set<string>& s, unordered_map<string, bool>& dp){
        
        if(dp[word] == true)
            return dp[word];
        
        for(int i=1; i<word.length(); i++){
            
            string prefix = word.substr(0, i); 
            string suffix = word.substr(i, word.length()-i);
            
            if((s.find(prefix) != s.end() && s.find(suffix) != s.end()) or 
               (s.find(prefix) != s.end() && dfs(suffix, s, dp))){
                dp[word] = true;
                return dp[word];
            }
        }
        
        return dp[word] = false;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        unordered_set<string> s(words.begin(), words.end());
        vector<string> res;
        
        unordered_map<string, bool> dp;
        for(auto& word: words){
            if(dfs(word, s, dp))
                res.push_back(word);
        }
        return res;
    }
};