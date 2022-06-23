class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> result;
        
        unordered_map<string, vector<string>> mp;
        
        for(auto& s : strs){
            mp[strsort(s)].push_back(s);
        }
        
        for(auto it : mp){
            result.push_back(it.second);
        }
        
        return result;
    }
    
    string strsort(string& s){
        
        int counter[26] = {0};
        for(auto& c : s){
            counter[c-'a']++;
        }
        
        string temp;
        for(int i=0; i<26; i++){
            temp += string(counter[i], i+'a');
        }
        
        return temp;
    }
};