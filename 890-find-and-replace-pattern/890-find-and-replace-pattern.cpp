class Solution {
public:
    
    bool isMatching(string word, string pattern){
        
        map<char, char> mp;
        set<char> s;
        
        for(int i=0; i<word.size(); i++){
            
            if(mp.find(pattern[i]) != mp.end()){
                if(mp[pattern[i]] != word[i]){
                    return false;
                }
            }
            else{
                if(s.find(word[i]) != s.end()) return false;
                
                mp[pattern[i]] = word[i];
                s.insert(word[i]);
            }
        }
        
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> res;
        
        for(auto word : words){
            
            if(isMatching(word, pattern) == true){
                res.push_back(word);
            }
        }
        
        return res;
    }
};