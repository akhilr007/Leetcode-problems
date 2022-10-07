template<typename Key, typename Value>
using MapIterator = typename std::map<Key,Value>::const_iterator;

template<typename Key, typename Value>
Key floorKey(const std::map<Key,Value>& input, const Key& key){
    /*
    map::upper_bound(>): 
    Returns an iterator pointing to the first element in the container 
    whose key is considered to go after k.
    
    If k is larger than any key in the map, then it returns map::end
    */
    MapIterator<Key, Value> it = input.upper_bound(key);
    if (it != input.begin()) {
        return (--it)->first;
    } else {
        //assume Key is int
        return -1;
    }
}

template<typename Key, typename Value>
Key ceilingKey(const std::map<Key,Value>& input, const Key& key){
	/*
	map::lower_bound(>=):
	Returns an iterator pointing to the first element 
	in the container whose key is not considered to go before k 
	(i.e., either it is equivalent or goes after).
	*/
    MapIterator<Key, Value> it = input.lower_bound(key);
    if (it != input.end()) {
        return it->first;
    } else {
        //assume Key is int
        return -1;
    }
}

class MyCalendar {
private:
    map<int, int> bookings;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
        int prevBooking = floorKey(bookings, start);
        int nextBooking = ceilingKey(bookings, start);
        
        if((prevBooking == -1 || bookings[prevBooking] <= start) && 
        (nextBooking == -1 || end <= nextBooking)){
            bookings[start] = end;
            return true;
        }
        
        return false;
        
    }
};
