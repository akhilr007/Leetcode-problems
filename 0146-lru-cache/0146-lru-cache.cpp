class Node {
public:
    int key;
    int value;
    Node* next;
    Node* prev;
    
    Node(int key, int value){
        this->key = key;
        this->value = value;
    }
};

class LRUCache {
    
private:
    void remove(Node* node){
        
        Node* prv = node->prev;
        Node* nxt = node->next;
        
        prv->next = nxt;
        nxt->prev = prv;
    }
    
    void insert(Node* node){
        
        Node* prv = right->prev;
        Node* nxt = right;
        
        node->prev = prv;
        node->next = nxt;
        
        prv->next = node;
        nxt->prev = node;
    }
    
public:
    int cap;
    unordered_map<int, Node*> cache;
    Node* left; // least recently used
    Node* right; // most recently used
    
    LRUCache(int capacity) {
        cap = capacity;
        left = new Node(0, 0);
        right = new Node(0, 0);
        
        left->next = right;
        right->prev = left; 
    }
    
    int get(int key) {
        
        if(cache.find(key) != cache.end()){
            int value = cache[key]->value;
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
        
        if(cache.size()>cap){
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
        }
    }
};
