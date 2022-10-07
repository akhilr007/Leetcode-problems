class MyCalendar {
    
    private TreeMap<Integer, Integer> bookings;
    public MyCalendar() {
        bookings = new TreeMap<>();   
    }
    
    public boolean book(int start, int end) {
        
        // prev booking start time of curr booking
        Integer prevBooking = bookings.floorKey(start);
        // next booking start time of curr booking
        Integer nextBooking = bookings.ceilingKey(start);
        
        if((prevBooking == null || bookings.get(prevBooking) <= start) &&
          (nextBooking == null || end <= nextBooking)){
            bookings.put(start, end);
            return true;
        }
        
        return false;
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(start,end);
 */