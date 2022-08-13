class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
         
        vector<int> res;
        if(words.size() > s.length()) return res;
        
        unordered_map<string, int> count;
        for(auto word : words){
            count[word]++;
        }
        
        int len = words[0].length();
        
        if(len*words.size() > s.length()) return res;
        
        for(int i=0; i<=s.length() - len*words.size(); i++){
            
            unordered_map<string, int> copy = count;
            
            for(int j=0; j<words.size(); j++){
                
                string str = s.substr(i+j*len, len);
                
                if(copy.find(str) != copy.end()){
                    
                    if(copy[str] == 1){
                        copy.erase(str);
                    }
                    else{
                        copy[str]--;
                    }
                    if(copy.size() == 0){
                        res.push_back(i);
                        break;
                    }
                }
                else break;
            }
        }
        
        return res;
    }
};