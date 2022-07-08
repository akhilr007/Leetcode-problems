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
    Node* head;
    Node* tail;
    
    void remove(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;
        
        prev->next = next;
        next->prev = prev;
    }
    
    void insert(Node* node){
        Node* prev = tail->prev;
        Node* next = tail;
        
        prev->next = node;
        next->prev = node;
        
        node->prev = prev;
        node->next = next;
    }
    
public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        
        head->next = tail;
        tail->prev = head; 
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
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
            Node* lru = head->next;
            remove(lru);
            cache.erase(lru->key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */