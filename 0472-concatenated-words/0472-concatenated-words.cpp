class Solution {
public:
    bool dfs(string& word, unordered_set<string>& s){
        
        for(int i=1; i<word.length(); i++){
            
            string prefix = word.substr(0, i); 
            string suffix = word.substr(i, word.length()-i);
            
            if((s.find(prefix) != s.end() && s.find(suffix) != s.end()) or 
               (s.find(prefix) != s.end() && dfs(suffix, s))){
                return true;
            }
        }
        
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        unordered_set<string> s(words.begin(), words.end());
        vector<string> res;
        
        for(auto& word: words){
            if(dfs(word, s))
                res.push_back(word);
        }
        return res;
    }
};