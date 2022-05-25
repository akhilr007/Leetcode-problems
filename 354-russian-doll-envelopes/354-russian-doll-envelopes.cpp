class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        sort(envelopes.begin(), envelopes.end(), [](vector<int>&a, vector<int>& b)->bool{
            return a[0]==b[0] ? b[1] < a[1] : a[0]<b[0];
        });
        
        vector<int> dp;
        int maxEl=1;
        
        for(auto e : envelopes){
            int height = e[1];
            
            int ind = lower_bound(dp.begin(), dp.end(), height)-dp.begin();
            if(ind == dp.size()){
                dp.push_back(height);
            }
            dp[ind]=height;
        }
        
        return dp.size();
    }
};