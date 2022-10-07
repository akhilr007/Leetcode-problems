class Booking{
    public int start;
    public int end;
    
    Booking(int start, int end){
        this.start = start;
        this.end = end;
    }
    
}

class MyCalendarTwo {
    
    private ArrayList<Booking> bookings;
    private ArrayList<Booking> doubleBookings;
    
    public MyCalendarTwo() {
        bookings = new ArrayList<>();
        doubleBookings = new ArrayList<>();
    }
    
    private boolean isOverlap(int s1, int e1, int s2, int e2){
        return Math.max(s1, s2) < Math.min(e1, e2);
    }
    
    public boolean book(int start, int end) {
        
        for(Booking doubleBooking : doubleBookings){
            if(isOverlap(doubleBooking.start, doubleBooking.end, start, end)){
                return false;
            }
        }
        
        for(Booking booking: bookings){
            if(isOverlap(booking.start, booking.end, start, end)){
                doubleBookings.add(new Booking(Math.max(booking.start, start), Math.min(booking.end, end)));
            }
        }
        
        bookings.add(new Booking(start, end));
        return true;
    }
}

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * boolean param_1 = obj.book(start,end);
 */