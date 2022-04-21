class MyHashSet {
private:
    int numBuckets;
    vector<list<int>> buckets;
    
    int hashFunction(int key){
        return key%numBuckets;
    }
    
public:
    MyHashSet() {
        numBuckets=15000;
        buckets = vector<list<int>> (numBuckets, list<int>{});
    }
    
    void add(int key) {
        int idx = hashFunction(key);
        
        if(find(buckets[idx].begin(), buckets[idx].end(), key) == buckets[idx].end()){
            buckets[idx].push_back(key);
        }
    }
    
    void remove(int key) {
        int idx = hashFunction(key);
        auto it = find(buckets[idx].begin(), buckets[idx].end(), key);
        if(it != buckets[idx].end()){
            buckets[idx].erase(it);
        }
    }
    
    bool contains(int key) {
        int idx = hashFunction(key);
        if(find(buckets[idx].begin(), buckets[idx].end(), key) == buckets[idx].end()){
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