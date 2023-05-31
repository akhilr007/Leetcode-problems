class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> arrivals;
    unordered_map<string, pair<double, double>> info;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        
        arrivals[id].first = stationName;
        arrivals[id].second = t;
    }
    
    void checkOut(int id, string stationName, int t) {
        
        auto arrival = arrivals[id];
        
        string key = arrival.first + "-" + stationName;
        
        int travelTime = t - arrival.second;
        
        info[key].first += travelTime;
        info[key].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        
        string key = startStation + "-" + endStation;
        return info[key].first / info[key].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */