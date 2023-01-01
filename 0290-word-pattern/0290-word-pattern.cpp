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
       
        map<char, string> charToWord;
        map<string, char> wordToChar;
        for(int i=0; i<pattern.length(); i++){
            
            char ch = pattern[i];
            // is char present in map ? if not then add it to map
            if(charToWord.find(ch) == charToWord.end() &&
              wordToChar.find(words[i]) == wordToChar.end()){
                charToWord[ch] = words[i];
                wordToChar[words[i]] = ch;
            }
            // if yes, then check if the word is same or not
            else{
                if(charToWord[ch] != words[i]) return false;
            }
        }
        
        return true;
    }
};