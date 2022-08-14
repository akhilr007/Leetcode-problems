class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if(wordSet.find(endWord) == wordSet.end()) return 0;
        
        queue<string> q;
        q.push(beginWord);
        int level = 1;
        
        while(!q.empty()){
            
            int size = q.size();
            while(size-- > 0){
                
                auto word = q.front();
                q.pop();
                
                if(word == endWord) return level;
                
                wordSet.erase(word);
                
                for(int i=0; i<word.length(); i++){
                    char c = word[i];
                    for(char ch='a'; ch<='z'; ch++){
                        word[i] = ch;
                        if(wordSet.find(word) != wordSet.end()){
                            q.push(word);
                        }
                    }
                    word[i] = c;
                }
            }
            
            level++;
            
        }
        
        return 0;
    }
};