

class LRUCache {
public:
    class Node{    
public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int key, int val){
        this->key = key;
        this->val = val;
    }
};
    int cap;
    unordered_map<int, Node*> m;
    Node* head, *tail;

    LRUCache(int capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node* newNode){
        
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }
    
    void deleteNode(Node* delNode){
        
        Node* delNext = delNode->next;
        Node* delPrev = delNode->prev;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }
    
    int get(int key) {
        
        if(m.find(key) != m.end()){
            Node* dataNode = m[key];
            int res = dataNode->val;
            // delete the key from map so that it can be put as last recently used
            m.erase(key);
            deleteNode(dataNode);
            addNode(dataNode);
            m[key] = head->next;
            return res;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        
        if(m.find(key) != m.end()){
            Node* existingNode = m[key];
            m.erase(key);
            deleteNode(existingNode);
        }
        
        if(m.size() == cap){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        addNode(new Node(key, value));
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */