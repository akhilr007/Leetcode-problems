class Solution {
public:
    int getNextIndex(vector<vector<int>>& events, int l, int endTime, int r){
        
        int result = r+1;
        while(l<=r){
            
            int mid = (l + r) / 2;
            
            if(events[mid][0] > endTime){
                result = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        
        return result;
    }
    
    int solve(int i, vector<vector<int>>& events, int k, vector<vector<int>>& dp){
        
        if(i >= events.size() || k == 0)
            return 0;
        
        if(dp[i][k] != -1)
            return dp[i][k];
        
        int startTime = events[i][0];
        int endTime = events[i][1];
        int value = events[i][2];
        
        int nextIdx = getNextIndex(events, i+1, endTime, events.size()-1);
        
        int take = value + solve(nextIdx, events, k-1, dp);
        int notTake = solve(i+1, events, k, dp);
        
        return dp[i][k] = max(take, notTake);
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        
        int n = events.size();
        sort(begin(events), end(events));
        
        vector<vector<int>> dp(n, vector<int> (k+1, -1));
        return solve(0, events, k, dp);
    }
};
