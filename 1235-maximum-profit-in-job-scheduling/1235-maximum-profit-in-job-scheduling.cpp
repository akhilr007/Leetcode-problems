class Solution {
public:
    int getNextIndex(vector<tuple<int, int, int>>& arr, int l, int currentJobEndTime, int r){
        
        int result=r+1;
        while(l<=r){
            
            int mid = l + (r-l)/2;
            
            auto& [startTime, endTime, profit] = arr[mid];
            if(startTime >= currentJobEndTime){
                result = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        
        return result;
    }
    
    int solve(vector<tuple<int, int, int>>& arr, int i, vector<int>& dp){
        
        if(i >= arr.size()) return 0;
        
        if(dp[i] != -1) return dp[i];
        auto& [curStartTime, curEndTime, curProfit] = arr[i];
        
        int next = getNextIndex(arr, i+1, curEndTime, arr.size()-1);
        
        int taken = curProfit + solve(arr, next, dp);
        int notTaken = solve(arr, i+1, dp);
        
        return dp[i] = max(taken, notTaken);
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n = startTime.size();
        vector<tuple<int, int, int>> arr(n);
        
        for(int i=0; i<n; i++){
            arr[i] = make_tuple(startTime[i], endTime[i], profit[i]);
        }
        
        sort(arr.begin(), arr.end());
        
        vector<int> dp(n, -1);
        return solve(arr, 0, dp);
    }
};