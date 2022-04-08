class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        stringstream ss(s);
        string temp;
        
        vector<string> words;
        
        while(ss >> temp){
            words.push_back(temp);
        }
        
        if(words.size() != pattern.length()) return false;
        
        map<char, string> mp;
        map<string, bool> vis;
        
        for(int i=0; i<pattern.size(); i++){
            
            char ch = pattern[i];
            
            if(mp.find(ch) != mp.end()){
                if(mp[ch] != words[i]) return false;
            }
            else{
                if(vis.find(words[i]) != vis.end()) return false;
                else{
                    mp[ch] = words[i];
                    vis[words[i]] = true;
                }
            }
        }
        
        return true;
    }
};