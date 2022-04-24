class UndergroundSystem {
    
    Map<Integer, ArrivalInfo> arrivals;
    Map<String, double[]> info;

    public UndergroundSystem() {
        arrivals = new HashMap<>();
        info = new HashMap<>();
    }
    
    public void checkIn(int id, String stationName, int t) {
        arrivals.put(id, new ArrivalInfo(id, stationName, t));
    }
    
    public void checkOut(int id, String stationName, int t) {
        ArrivalInfo arrival = arrivals.get(id);
        
        String key = arrival.stationName + "_" + stationName;
        
        double[] pair = info.getOrDefault(key, new double[2]);
        
        int time = t - arrival.t;
        pair[0] += time;
        pair[1]++;
        
        info.put(key, pair);
    }
    
    public double getAverageTime(String startStation, String endStation) {
        
        String key = startStation + "_" + endStation;
        double[] data = info.get(key);
        
        return data[0] / data[1];
    }
    
    class ArrivalInfo{
        int id;
        String stationName;
        int t;
        
        ArrivalInfo(int id, String stationName, int t){
            this.id = id;
            this.stationName = stationName;
            this.t = t;
        }
    }
}

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem obj = new UndergroundSystem();
 * obj.checkIn(id,stationName,t);
 * obj.checkOut(id,stationName,t);
 * double param_3 = obj.getAverageTime(startStation,endStation);
 */