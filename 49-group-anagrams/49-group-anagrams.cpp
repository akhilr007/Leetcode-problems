class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        
        vector<vector<string>> ans;
        if(str.size() == 0) return ans;
        
        unordered_map<string, vector<string>> mp;
        
        for(auto s: str){
            
            string temp = s;
            sort(temp.begin(), temp.end());
            
            mp[temp].push_back(s);
        }
        
        for(auto it : mp){
            
            ans.push_back(it.second);
        }
        
        return ans;
    }
};