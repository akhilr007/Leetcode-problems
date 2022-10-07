class MyCalendarTwo {
private:
    map<int, int> m;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        
        m[start]++;
        m[end]--;
        
        int activeBookings=0;
        for(auto it = m.begin(); it != m.end(); it++){
            
            activeBookings += it->second;
            if(activeBookings > 2){
                m[start]--;
                m[end]++;
                return false;
            }
        }
        
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */