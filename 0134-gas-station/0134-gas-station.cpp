class Solution {
private:
    int bruteForce(vector<int>& gas, vector<int>& cost){
        
        int n = gas.size();
        
        for(int i=0; i<n; i++){
            
            if(gas[i] < cost[i])
                continue;
            
            int costForMovingToNextStation = cost[i];
            
            int j = (i + 1) % n;
            int gasEarnFromNextStationJ = gas[j];
            
            int curGas = gas[i] - costForMovingToNextStation + gasEarnFromNextStationJ;
            
            while(j != i){
                
                if(curGas < cost[j]) break;
                
                costForMovingToNextStation = cost[j];
                j = (j + 1) % n;
                
                gasEarnFromNextStationJ = gas[j];
                
                curGas = curGas - costForMovingToNextStation + gasEarnFromNextStationJ;
            }

            if(i == j) return i;
        }
        
        return -1;
    }
    
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        
        int totalGas = 0;
        int totalCost = 0;
        
        for(int i=0; i<n; i++){
            totalGas += gas[i];
            totalCost += cost[i];
        }
        
        if(totalGas < totalCost) return -1;
        
        int result = 0;
        int total=0;
        
        for(int i=0; i<n; i++){
            total += gas[i] - cost[i];
            if(total < 0) {
                total = 0;
                result = i+1;
            }
        }
        
        return result;
    }
};