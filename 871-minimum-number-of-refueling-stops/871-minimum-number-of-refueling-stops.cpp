class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int xCurrent = startFuel;
        int noOfStopsNeeded = 0;
        
        priority_queue<int> pq;
        
        for(auto station : stations){
            
            int nextStationX = station[0];
            int fuelAtStation = station[1];
            
            while(xCurrent < nextStationX){
                
                if(pq.empty()) return -1;
                
                int maxFuel = pq.top();
                pq.pop();
                
                xCurrent += maxFuel;
                noOfStopsNeeded++;
            }
            
            pq.push(fuelAtStation);
        }
        
        while(xCurrent < target){
            
            if(pq.empty()) return -1;
            
            int maxFuel = pq.top();
            pq.pop();
            
            xCurrent += maxFuel;
            noOfStopsNeeded++;
        }
        
        return noOfStopsNeeded;
    }
};