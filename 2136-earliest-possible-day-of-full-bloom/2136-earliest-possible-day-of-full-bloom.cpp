class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        int n = plantTime.size();
        vector<pair<int, int>> plant(n);
        for(int i=0; i<n; i++){
            plant[i].first = growTime[i];
            plant[i].second = plantTime[i];
        }
        
        sort(plant.begin(), plant.end(), greater<pair<int, int>>());
        
        int time=0;
        int maxi=0;
        
        for(int i=0; i<n; i++){
            
            time += plant[i].second;
            maxi = max(maxi, time + plant[i].first);
        }
        
        return maxi;
    }
};