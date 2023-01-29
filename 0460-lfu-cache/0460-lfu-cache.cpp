struct Node{
    int key;
    int val;
    int cnt;
    Node* next;
    Node* prev;
    
    Node(int key_, int val_){
        key = key_;
        val = val_;
        next = NULL;
        prev = NULL;
        cnt = 1;
    }
};

struct List{
    int size;
    Node* left; // LRU
    Node* right; // MRU
    
    List(){
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
        size = 0;
    }
    
    void insert(Node* node){
        
        Node* prev = right->prev;
        Node* nxt = right;
        
        prev->next = node;
        nxt->prev = node;
        
        node->prev = prev;
        node->next = nxt;
        
        size++;
    }
    
    void remove(Node* node){
        
        Node* prev = node->prev;
        Node* nxt = node->next;
        
        prev->next = nxt;
        nxt->prev = prev;
        size--;
    }
};

class LFUCache {
unordered_map<int, Node*> keyNode;
unordered_map<int, List*> freqListMap;
int maxSizeCache ;
int minFreq;
int curSize;
public:
    LFUCache(int capacity) {
        
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;
    }
    
    void updateFreqListMap(Node* node){
        
        keyNode.erase(node->key);
        freqListMap[node->cnt]->remove(node);
        
        if(node->cnt == minFreq && freqListMap[node->cnt]->size == 0){
            minFreq++;
        }
        
        List* nextHigherFrequencyList = new List();
        if(freqListMap.find(node->cnt + 1) != freqListMap.end()){
            nextHigherFrequencyList = freqListMap[node->cnt + 1];
        }
        
        node->cnt += 1;
        nextHigherFrequencyList->insert(node);
        freqListMap[node->cnt] = nextHigherFrequencyList;
        keyNode[node->key] = node;
        
    }
    
    int get(int key) {
        
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            int value = node->val;
            updateFreqListMap(node);
            return value;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if(maxSizeCache == 0)
            return;
        
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node->val = value;
            updateFreqListMap(node);
        }
        else{
            if(curSize == maxSizeCache){
                List* list = freqListMap[minFreq];
                keyNode.erase(list->left->next->key);
                freqListMap[minFreq]->remove(list->left->next);
                curSize--;
            }
            
            curSize++;
            minFreq = 1;
            
            List* listFreq = new List();
            
            if(freqListMap.find(minFreq) != freqListMap.end()){
                listFreq = freqListMap[minFreq];
            }
            
            Node* node = new Node(key, value);
            listFreq->insert(node);
            keyNode[key] = node;
            freqListMap[minFreq] = listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */