struct Node {
    Node* links[26];
    bool flag = false;
    
    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }
    
    void insert(char ch, Node* node){
        links[ch-'a'] = node;
    }
    
    Node* getNode(char ch){
        return links[ch-'a'];
    }
    
    void setEnd(){
        flag = true;
    }
    
    bool isEnd(){
        return flag;
    }
    
    bool search(string& word, Node* node, int idx){
        
        if(idx == word.length()){
            return node->isEnd();
        }
        
        if(word[idx] == '.'){
            
            for(int i=0; i<26; i++){
                if(node->links[i] != NULL && search(word, node->links[i], idx+1)){
                    return true;
                }
            }
            
            return false;
        }
        else{
            if(node->containsKey(word[idx])){
                
                node = node->getNode(word[idx]);
                return search(word, node, idx+1);
            }
            else return false;
        }
    }
};

class Trie{
private:
    Node* root;
    
public:
    Trie(){
        root = new Node();
    }
    
    void insert(string& word){
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->containsKey(word[i])){
                node->insert(word[i], new Node());
            }
            
            node = node->getNode(word[i]);
        }
        
        node->setEnd();
    }
    
    bool searchInTrie(string& word){
        
        Node* node = root;
        
        return node->search(word, node, 0);
        
    }
};

class WordDictionary {
public:
    Trie trie;
    WordDictionary() {
    }
    
    void addWord(string word) {
        
        trie.insert(word);
    }
    
    bool search(string word) {
        
        return trie.searchInTrie(word);
    }
};

