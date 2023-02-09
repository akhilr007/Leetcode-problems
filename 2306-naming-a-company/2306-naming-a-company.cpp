class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        
        long long res = 0;
        unordered_map<char, unordered_set<string>> mp;
        
        for(auto &word: ideas){
            mp[word[0]].insert(word.substr(1));
        }
        
        for(auto& [char1, _] : mp){
            
            for(auto& [char2, _]: mp){
                
                if(char1 == char2)
                    continue;
                
                long long duplicates = 0;
                
                for(auto& word: mp[char1])
                    if(mp[char2].find(word) != mp[char2].end()){
                        duplicates++;
                    }
                
                long long distinct1 = mp[char1].size() - duplicates;
                long long distinct2 = mp[char2].size() - duplicates;
                
                res += distinct1 * distinct2;
            }
        }
        
        return res;
    }
};