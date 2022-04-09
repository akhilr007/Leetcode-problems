class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        
        unordered_map<int, int> mp;
        
        int maxSplit=0;
        
        for(vector<int> list : wall){
            int prefixSum=0;
            for(int i=0; i<list.size()-1; i++){
                int val = list[i];
                prefixSum += val;
                mp[prefixSum]++;
                maxSplit = max(maxSplit, mp[prefixSum]);
            }
        }
        
        return wall.size()-maxSplit;
    }
};