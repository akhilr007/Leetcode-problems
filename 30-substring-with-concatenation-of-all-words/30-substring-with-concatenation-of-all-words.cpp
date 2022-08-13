class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        vector<int> result;
        
        int len = words[0].length();
        
        unordered_map<string, int> count;
        for(auto word : words){
            count[word]++;
        }
        
        if(len * words.size() > s.length()) return result;
        
        for(int i=0; i<=s.length() - len*words.size(); i++){
            
            unordered_map<string, int> copy = count;
            for(int j=0; j<words.size(); j++){
                
                string str = s.substr(i + j*len, len);
                
                if(copy.find(str) != copy.end()){
                    if(copy[str] == 1) {
                        copy.erase(str);
                    }
                    else copy[str]--;
                    
                    if(copy.size() == 0){
                        result.push_back(i);
                        break;
                    }
                }
                else break;
            }
        }
        
        return result;
    }
};