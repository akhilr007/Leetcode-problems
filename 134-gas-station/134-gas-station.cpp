class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int gasCost=0, travelCost=0;
        for(int i=0; i<gas.size(); i++){
            gasCost += gas[i];
            travelCost += cost[i];
        }
        
        if(gasCost < travelCost) return -1;
        
        int total=0;
        int start=0;
        
        for(int i=0; i<gas.size(); i++){
            
            total += gas[i]-cost[i];
            
            if(total < 0){
                total = 0;
                start = i+1;
            }
        }
        
        return start;
    }
};