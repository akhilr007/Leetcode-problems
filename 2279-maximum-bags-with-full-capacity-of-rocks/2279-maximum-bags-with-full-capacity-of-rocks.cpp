class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        
        int n = capacity.size();
        
        vector<int> required_rocks(n, 0);
        
        for(int i=0; i<n; i++){
            int current_rock = rocks[i];
            int capacity_rock = capacity[i];
            
            required_rocks[i] = capacity_rock - current_rock;
        }
        
        sort(begin(required_rocks), end(required_rocks));
        
        int count=0;
        for(int i=0; i<n; i++){
            if(additionalRocks >= required_rocks[i]){
                additionalRocks -= required_rocks[i];
                count++;
            }
            else break;
        }
        
        return count;
    }
};