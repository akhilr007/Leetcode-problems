struct Node{
    Node* links[26];
    bool flag = false;
    
    bool containsKey(char ch){
        return links[ch -'a'] != NULL;
    }
    
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    
    Node* get(char ch){
        
        return links[ch-'a'];
    }
    
    void setEnd(){
        flag = true;
    }
    
    bool isEnd(){
        return flag;
    }
    
    bool find(string& word, Node* node, int ind){
        
        if(ind == word.size()) return node->isEnd();
        
        if(word[ind] == '.'){
            
            for(int j=0; j<26; j++){
                if(node->links[j] != NULL && find(word, node->links[j], ind+1)){
                    return true;
                }
                
            }
            return false;
        }
        
        else{
            
            if(node->containsKey(word[ind])){
                node = node->get(word[ind]);
                return find(word, node, ind+1);
            }
            else return false;
        }
    }
};

class WordDictionary {
private : Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        
        Node* node = root;
        
        for(int i=0; i<word.length(); i++){
            
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        
        Node* node = root;
        
        return root->find(word, node, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */