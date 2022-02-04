class Solution {
public:
    static bool compare(const pair<int, double>& a, const pair<int, double>& b){
        return a.first <= b.first;
    }
    
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n = position.size();
        
        vector<pair<int, double>> cardata(n);
        // first -> position of car
        // second -> time taken to reach destination
        
        for(int i=0; i<n; i++){
            cardata[i].first = position[i];
            cardata[i].second = (double)(target-position[i])/speed[i];
        }
        
        sort(cardata.begin(), cardata.end(), compare);
        
        int no_of_fleet=1;
        double tt = cardata[n-1].second;
        
        for(int i=n-2; i>=0; i--){
            if(cardata[i].second > tt){
                no_of_fleet++;
                tt = cardata[i].second;
            }
        }
        
        return no_of_fleet;
        
        
    }
};