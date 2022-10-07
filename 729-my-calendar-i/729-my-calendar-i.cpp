class MyCalendar {
private:
    map<int, int> bookings;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
        auto nextBooking = bookings.upper_bound(start);
        
        if(nextBooking == bookings.end() || end <= nextBooking->second){
            bookings[end] = start;
            return true;
        }
        
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */