class SmallestInfiniteSet {
public:
    set<int> st;
    int curSmallest;
    
    SmallestInfiniteSet() {
        curSmallest = 1;
    }
    
    int popSmallest() {
        
        int result;
        
        if(!st.empty()){
            result = *st.begin();
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
        
        st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */