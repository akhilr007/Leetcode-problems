class Solution {
public:
    static bool endsWith(std::string_view str, std::string_view suffix){
    return str.size() >= suffix.size() && 0 == str.compare(str.size()-suffix.size(), suffix.size(), suffix);
}

    int minimumLengthEncoding(vector<string>& words) {
        
        unordered_set<string> wordSet;
        for(auto word : words){
            wordSet.insert(word);
        }
        
        vector<string> wordList;
        for(auto word: wordSet){
            wordList.push_back(word);
        }
        
        unordered_set<string> duplicateList;
        
        for(int i=0; i<wordList.size(); i++){
            for(int j=0; j<wordList.size(); j++){
                
                if(i!=j){
                    if(endsWith(wordList[i], wordList[j])){
                        duplicateList.insert(wordList[j]);
                    }
                }
            }
        }
        
        int count=0;
        for(auto word: wordList){
            // 1 for #
            if(duplicateList.find(word) == duplicateList.end()){
                count += word.length() + 1;
            }
        }
        
        return count;
    }
};