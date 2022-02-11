class Solution {
public:
    
    static bool compare(const pair<int, double> &a, const pair<int, double>&b){
        return a.first <= b.first;
    }
    
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n=position.size();
        vector<pair<int, double>> carData(n);
        
        for(int i=0; i<n; i++){
            carData[i].first = position[i];
            carData[i].second = (double)(target-position[i])/speed[i];
        }
        
        sort(carData.begin(), carData.end(), compare);
        
        int nof=1;
        double tt = carData[n-1].second;
        
        for(int i=n-2; i>=0; i--){
            if(carData[i].second > tt){
                nof++;
                tt = carData[i].second;
            }
        }
        
        return nof;
    }
};