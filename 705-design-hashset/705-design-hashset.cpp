class MyHashSet {
private:
    int numBuckets;
    vector<list<int>> bucket;
    
    int hashFunction(int key){
        return key%numBuckets;
    }
    
public:
    MyHashSet() {
        numBuckets = 15000;
        bucket = vector<list<int>> (numBuckets, list<int>{});
    }
    
    void add(int key) {
        
        int i = hashFunction(key);
        
        if(find(bucket[i].begin(), bucket[i].end(), key) == bucket[i].end()){
            bucket[i].push_back(key);
        }
    }
    
    void remove(int key) {
        
        int i = hashFunction(key);
        
        auto it = find(bucket[i].begin(), bucket[i].end(), key);
        if(it != bucket[i].end()){
            bucket[i].erase(it);
        }
    }
    
    bool contains(int key) {
        
        int i = hashFunction(key);
        
        if(find(bucket[i].begin(), bucket[i].end(), key) == bucket[i].end()){
            return false;
        }
        return true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */