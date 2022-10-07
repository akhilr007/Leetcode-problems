class Booking{
public:
    int start;
    int end;
    
    Booking(int start, int end){
        this->start = start;
        this->end = end;
    }
};

class MyCalendarTwo {
private:
    vector<Booking> bookings;
    vector<Booking> doubleBookings;
public:
    MyCalendarTwo() {
        
    }
    
    bool isOverlap(int s1, int e1, int s2, int e2){
        
        return max(s1, s2) < min(e1, e2);
    }
    
    bool book(int start, int end) {
        
        for(auto doubleBooking : doubleBookings){
            if(isOverlap(doubleBooking.start,  doubleBooking.end, start, end)){
                return false;
            }
        }
        
        for(auto booking: bookings){
            if(isOverlap(booking.start, booking.end, start, end)){
                doubleBookings.push_back(Booking(max(booking.start, start), min(booking.end, end)));
            }
        }
        
        bookings.push_back(Booking(start, end));
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */