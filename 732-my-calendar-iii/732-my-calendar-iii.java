class MyCalendarThree {
    
    private TreeMap<Integer, Integer> tmap;
    public MyCalendarThree() {
        tmap = new TreeMap<>();
    }
    
    public int book(int start, int end) {
        
        tmap.put(start, tmap.getOrDefault(start, 0) + 1);
        tmap.put(end, tmap.getOrDefault(end, 0) - 1);
        
        int activeBookings = 0;
        int maxBookings = 0;
        
        for(int events : tmap.values()){
            
            activeBookings += events;
            maxBookings = Math.max(activeBookings, maxBookings);
        }
        
        return maxBookings;
    }
}

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */