class RandomizedCollection {
private:
    vector<int> v;
    unordered_map<int, unordered_set<int>> m;
    
public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool flag;
        unordered_set<int> s;
        if(m.find(val) != m.end()){
            flag = false;
            s = m[val];
        }
        else{
            flag = true;
            m[val] = s;
        }
        
        v.push_back(val);
        s.insert(v.size()-1);
        m[val] = s;
        return flag;
    }
    
    bool remove(int val) {
        
        unordered_set<int> s;
        
        if(m.find(val) == m.end()){
            return false;
        }
        else{
            s = m[val];
        }
        
        int remidx = -1;
        for(int i: s){
            remidx = i;
            break;
        }
        
        s.erase(remidx);
        
        m[val] = s;
        if(m[val].size() == 0){
            m.erase(val);
        }
        
        if(remidx == v.size()-1){
            v.pop_back();
        }
        else{
            v[remidx] = v.back();
            v.pop_back();
            
            int newval = v[remidx];
            unordered_set<int> temp = m[newval];
            
            temp.erase(v.size());
            temp.insert(remidx);
            
            m[newval] = temp;
        }
        
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */