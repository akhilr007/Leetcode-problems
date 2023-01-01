class Solution {
private:
    vector<string> getWordsFromString(string& s){
        
        stringstream ss(s);
        string word;
        
        vector<string> res;
        while(ss >> word){
            res.push_back(word);
        }
        return res;
    }
public:
    bool wordPattern(string pattern, string s) {
        
        vector<string> words = getWordsFromString(s);
        if(pattern.size() != words.size()) return false;
       
        unordered_map<char, string> charToWord;
        unordered_map<string, bool> wordVisited;
        
        for(int i=0; i<pattern.length(); i++){
            
            char ch = pattern[i];
            
            // if char is present
            if(charToWord.find(ch) != charToWord.end()){
                
                // then word should match 
                if(charToWord[ch] != words[i]) return false;
            }
            else{
                // if char is not present
                if(wordVisited.find(words[i]) != wordVisited.end()) return false;
                else{
                    charToWord[ch] = words[i];
                    wordVisited[words[i]] = true;
                }
            }
        }
        
        return true;
        
        return true;
    }
};