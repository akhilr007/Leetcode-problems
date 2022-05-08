class RandomizedCollection{
private:
    vector<int> v;
    unordered_map<int, unordered_set<int>> m;

public:
    RandomizedCollection(){

    }

    bool insert(int val){

        unordered_set<int> s;
        bool flag;
        if(m.find(val) != m.end()){
            flag = false;
            s = m[val];
        }
        else{
            flag = true;
        }

        v.push_back(val);
        s.insert(v.size()-1);
        m[val] = s;

        return flag;
    }

    bool remove(int val){

        unordered_set<int> s;

        // if val not found in map return false
        if(m.find(val) == m.end()){
            return false;
        }
        else{
            // if fount, get the set of the val
            s = m[val];
        }

        int remidx;
        // pick the first element from set
        for(int i : s){
            remidx = i;
            break;
        }

        // remove the remidx from set
        s.erase(remidx);
        // update the m[val]
        m[val] = s;

        // if m[val]-> set list size is 0 then erase val from m
        if(m[val].size() == 0){
            m.erase(val);
        }

        // now remove the element at remidx from vector
        // if remidx is at the last index of vector then simply remove it

        if(remidx == v.size()-1){
            v.pop_back();
        }
        else{
            v[remidx] = v.back();
            v.pop_back();

            int newval = v[remidx];

            // change the index of newval
            unordered_set<int> temp = m[newval];

            temp.erase(v.size());
            temp.insert(remidx);

            m[newval] = temp;
        }

        return true;

    }

    int getRandom(){
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */