class MyHashSet {
public:
    
    const int bucket_size = 15000;
    vector<list<int>> bucket;
    
    MyHashSet() {
        bucket = vector<list<int>> (bucket_size, list<int> {});
    }
    
    void add(int key) {
        
        int index = key % bucket_size;
        if(find(begin(bucket[index]), end(bucket[index]), key) == end(bucket[index])){
            bucket[index].push_back(key);
        }
    }
    
    void remove(int key) {
        
        int index = key % bucket_size;
        
        auto it = find(begin(bucket[index]), end(bucket[index]), key);
        if(it != end(bucket[index])){
            bucket[index].erase(it);
        }
    }
    
    bool contains(int key) {
        
        int index = key % bucket_size;
        
        if(find(begin(bucket[index]), end(bucket[index]), key) != end(bucket[index])){
            return true;
        }
        
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */