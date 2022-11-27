class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int, int> maps[n];
        
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                
                long commonDifference = (long)nums[i] - (long)nums[j];
                if(commonDifference <= INT_MIN or commonDifference >= INT_MAX) continue;
                
                int apsEndingWithJ=0, apsEndingWithI=0;
                if(maps[j].find(commonDifference) != maps[j].end()){
                    apsEndingWithJ = maps[j][commonDifference];
                }
                if(maps[i].find(commonDifference) != maps[i].end()){
                    apsEndingWithI = maps[i][commonDifference];
                }
                
                ans += apsEndingWithJ;
                maps[i][commonDifference] = apsEndingWithJ + apsEndingWithI + 1;
            }
        }
        
        return ans;
    }
};