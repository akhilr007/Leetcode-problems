class MyCalendarThree {
private:
    map<int, int> m;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        
        m[start]++;
        m[end]--;
        
        int maxBookings=0;
        int activeBookings=0;
        for(auto it = m.begin(); it != m.end(); it++){
            
            activeBookings += it->second;
            maxBookings = max(maxBookings, activeBookings);
        }
        
        return maxBookings;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */