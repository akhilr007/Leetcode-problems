class Solution {
public:
    int solve(int idx, vector<int>& satisfaction, int curTime, int n,
             vector<vector<long long>>& dp){
        
        if(idx >= n)
            return 0;
        if(dp[idx][curTime] != -1)
            return dp[idx][curTime];
        
        long long take = ((long long)curTime * (long long)satisfaction[idx]) + solve(idx+1, satisfaction, curTime+1, n, dp);
        long long notTake = solve(idx+1, satisfaction, curTime, n, dp);
        
        return dp[idx][curTime] = max(take, notTake);
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        
        int n = satisfaction.size();
        sort(begin(satisfaction), end(satisfaction));
        
        vector<vector<long long>> dp(n+1, vector<long long>(n+1, -1));
        return solve(0, satisfaction, 1, n, dp);
    }
};