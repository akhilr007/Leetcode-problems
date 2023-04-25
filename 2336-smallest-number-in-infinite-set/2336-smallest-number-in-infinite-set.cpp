class SmallestInfiniteSet {
public:
    unordered_set<int> st;
    priority_queue <int, vector<int>, greater<int>> pq;
    int curSmallest;
    
    SmallestInfiniteSet() {
        curSmallest = 1;
    }
    
    int popSmallest() {
        
        int result;
        
        if(!pq.empty()){
            result = pq.top();
            pq.pop();
            st.erase(st.begin());
            return result;
        }
        
        result = curSmallest;
        curSmallest ++;
        
        return result;
    }
    
    void addBack(int num) {
        
        if(num >= curSmallest || st.find(num) != st.end())
            return;
        
        pq.push(num);
        st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */