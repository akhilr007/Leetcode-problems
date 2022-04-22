class MyHashMap {
private:
    vector<list<pair<int, int>>> map; // pair -> {entry, value}
    const int SIZE=769; // prime number
    
    int hashFunction(int key){
        return key%SIZE;
    }
    
public:
    MyHashMap() {
        map.resize(SIZE);
    }
    
    void put(int key, int value) {
        
        int bucket = hashFunction(key);
        
        for(auto &entry : map[bucket]){
            
            if(entry.first == key){
                entry.second = value;
                return;
            }
        }
        
        map[bucket].push_back(make_pair(key, value));
    }
    
    int get(int key) {
        
        int bucket = hashFunction(key);
        // if there is no element at map[bucket] return -1;
        if(map[bucket].size() == 0){
            return -1;
        }
        
        // search for the key in map
        for(auto& entry : map[bucket]){
            if(entry.first == key){
                return entry.second;
            }
        }
        
        // if key is not found
        return -1;
    }
    
    void remove(int key) {
        
        int bucket = hashFunction(key);
        
        if(map[bucket].size()==0){
            return;
        }
        
        pair<int, int> toRemove;
        toRemove.first = -1;
        toRemove.second = -1;
        
        for(auto& entry : map[bucket]){
            
            if(entry.first == key){
                toRemove.first=entry.first;
                toRemove.second = entry.second;
            }
        }
        
        if(toRemove.first==-1) return;
        map[bucket].remove(toRemove);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */