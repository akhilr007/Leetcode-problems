class TimeMap {
private:
    unordered_map<string, vector< pair<int, string> > > m;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        
        if(m.find(key) == m.end()) return "";
        
        auto& values = m[key];
        
        if(values.size() == 0) return "";
        
        string res="";
        int L=0, R=values.size()-1;
        
        while(L <= R){
            
            int mid = L + (R-L)/2;
            
            if(values[mid].first <= timestamp){
                res = values[mid].second;
                L = mid + 1;
            }
            else{
                R = mid - 1;
            }
        }
        
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */