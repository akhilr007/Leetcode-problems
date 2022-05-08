class RandomizedSet{
private:
    vector<int> v;
    unordered_map<int, int> m;

public:
    RandomizedSet(){

    }

    bool insert(int val){

        if(m.find(val) != m.end()){
            return false;
        }

        v.push_back(val);
        m[val] = v.size()-1;

        return true;
    }

    bool remove(int val){

        if(m.find(val) == m.end()){
            return false;
        }

        // find the index which needs to be removed
        auto it = m.find(val);
        // replace the val at that index with last element of vector
        v[it->second] = v.back();
        // remove the last element
        v.pop_back();

        // change the last val index to cur index
        m[v[it->second]] = it->second;

        // delete the val
        m.erase(val);

        return true;
    }

    int getRandom(){
        return v[rand()%v.size()];
    }
};