class Solution {
public:
    unordered_map<string, int> mp;
    vector<vector<string>> ans;
    string b;
    
    void dfs(string word, vector<string>& seq){
        
        if(word == b){
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        
        int steps = mp[word];
        for(int i=0; i<word.length(); i++){
            
            char original = word[i];
            for(char ch='a'; ch<='z'; ch++){
                word[i] = ch;
                if(mp.find(word) != mp.end() && mp[word] + 1 == steps){
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        b = beginWord;
        unordered_set<string> st(wordList.begin(), wordList.end());
        
        queue<string> q;
        q.push(beginWord);
    
        mp[beginWord] = 1;
        st.erase(beginWord);
        
        int wordSize = beginWord.length();
        while(!q.empty()){
            
            string word = q.front();
            q.pop();
            int steps = mp[word];
            
            if(word == endWord) break;
            
            for(int i=0; i<wordSize; i++){
                char original = word[i];
                for(char ch='a'; ch<='z'; ch++){
                    word[i] = ch;
                    if(st.count(word)){
                        q.push(word);
                        mp[word] = steps + 1;
                        st.erase(word);
                    }
                }
                
                word[i] = original;
            }
        }
        
        if(mp.find(endWord) != mp.end()){
            cout<<"a";
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        
        return ans;
    }
};