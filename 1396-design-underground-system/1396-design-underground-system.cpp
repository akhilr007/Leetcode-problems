class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> info;
    unordered_map<string, vector<int>> arrivals;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        info[id].first = stationName;
        info[id].second = t;
    }
    
    void checkOut(int id, string stationName, int t) {
        
        auto passenger = info[id];
        
        string travelDetails = passenger.first + "-" + stationName;
        int startTime = passenger.second;
        
    
        arrivals[travelDetails].push_back(t-startTime);
        
    }
    
    double getAverageTime(string startStation, string endStation) {
        
        string travelDetails = startStation + "-" + endStation;
        auto details = arrivals[travelDetails];
        
        double averageTime = 0;
        int totalTravelTime = details.size();
        
        for(auto t: details){
            averageTime += t;
        }
        
        averageTime = averageTime / totalTravelTime;
        return averageTime;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */