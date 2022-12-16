class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;
        
        for(int i=1; i<=k+1; i++){
            vector<int> tempPrices = prices;
            for(int j=0; j<flights.size(); j++){
                int s = flights[j][0]; // src
                int d = flights[j][1]; // dest
                int p = flights[j][2]; // price
                
                if(prices[s] == INT_MAX) continue;
                
                if(prices[s] + p < tempPrices[d]){
                    tempPrices[d] = prices[s] + p;
                }
            }
            
            prices = tempPrices;
        }
        
        if(prices[dst] == INT_MAX) return -1;
        return prices[dst];
    }
};