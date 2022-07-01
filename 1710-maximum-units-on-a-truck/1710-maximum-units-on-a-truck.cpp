class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b){
        
        if(a[1] == b[1]){
            return a[0] < b[0];
        }
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(), boxTypes.end(), comp);
        
        int maxUnits=0;
        
        for(int i=0; i<boxTypes.size(); i++){
            
            if(boxTypes[i][0] <= truckSize){
                maxUnits += boxTypes[i][1] * boxTypes[i][0];
                truckSize -= boxTypes[i][0];
            }
            else{
                maxUnits += truckSize * boxTypes[i][1];
                truckSize -= truckSize;
            }
        }
        
        return maxUnits;
    }
};