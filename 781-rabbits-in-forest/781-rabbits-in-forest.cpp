class Solution {
public:
    int numRabbits(vector<int>& answers) {
        
        unordered_map<int, int> mp;
        
        for(int val : answers){
            mp[val]++;
        }
        
        int ans=0;
        for(auto it: mp){
            int groupSize = it.first+1;
            int reportees = it.second;
            
            int noOfGroupsNeeded = ceil(reportees*1.0 / groupSize*1.0);
            
            ans += groupSize * noOfGroupsNeeded;
        }
        
        return ans;
    }
};