class Pair{
    
    public String value;
    public int timeStamp;
    
    Pair(String value, int timeStamp){
        this.value = value;
        this.timeStamp = timeStamp;
    }
}

class TimeMap {
    
    private Map<String, ArrayList<Pair> > map;
    
    public TimeMap() {
        map = new HashMap<>();   
    }
    
    public void set(String key, String value, int timestamp) {
        
        if(map.containsKey(key) == false){
            map.put(key, new ArrayList<>());
            ArrayList<Pair> p = map.get(key);
            p.add(new Pair(value, timestamp));
        }
        else{
            ArrayList<Pair> p = map.get(key);
            p.add(new Pair(value, timestamp));
        }
    }
    
    public String get(String key, int timestamp) {
        
        if(map.containsKey(key) == false) return "";
        
        ArrayList<Pair> values = map.get(key);
        
        if(values.size() == 0) return "";
        
        int L=0, R=values.size()-1;
        
        String res="";
        while(L <= R){
            
            int mid = L + (R-L)/2;
            
            if(values.get(mid).timeStamp <= timestamp){
                res = values.get(mid).value;
                L = mid + 1;
            }
            else{
                R = mid - 1;
            }
        }
        
        return res;
    }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap obj = new TimeMap();
 * obj.set(key,value,timestamp);
 * String param_2 = obj.get(key,timestamp);
 */