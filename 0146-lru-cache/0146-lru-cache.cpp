class Node{
public:
    int key;
    int val;
    Node* next;
    Node* prev;
    
    Node(int key, int val){
        this->key = key;
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> cache;
    Node* left;
    Node* right; // left -> LRU right = most recently used
    
    void remove(Node* node){
        
        Node* prev = node->prev;
        Node* nxt = node->next;
        
        prev->next = nxt;
        nxt->prev = prev;
    }
    
    void insert(Node* node){
        
        Node* prev = right->prev;
        Node* nxt = right;
        
        prev->next = node;
        nxt->prev = node;
        
        node->prev = prev;
        node->next = nxt;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        left = new Node(0, 0);
        right = new Node(0, 0);
        
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        
        if(cache.find(key) != cache.end()){
            int value = cache[key]->val;
            remove(cache[key]);
            insert(cache[key]);
            return value;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        
        if(cache.find(key) != cache.end()){
            remove(cache[key]);
        }
        
        cache[key] = new Node(key, value);
        insert(cache[key]);
        
        if(cache.size() > cap){
            Node* LRU = left->next;
            remove(cache[LRU->key]);
            cache.erase(LRU->key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */