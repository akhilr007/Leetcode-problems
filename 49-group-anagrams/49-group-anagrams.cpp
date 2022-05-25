class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> m;
        
        vector<vector<string>> result;
        
        for(string s : strs){
            string temp = s;
            sort(temp.begin(), temp.end());
            
            m[temp].emplace_back(s);
            
        }
        
        for(auto it : m){
            result.emplace_back(it.second);
        }
        
        return result;
    }
};