class Solution {
public:
    int f(int idx, int d, vector<int>& jobDifficulty, vector<vector<int>>& dp){
        
        if(d == 1){
            int mx=0;
            for(int i=idx; i<jobDifficulty.size(); i++){
                mx = max(mx, jobDifficulty[i]);
            }
            return mx;
        }
        
        if(dp[idx][d] != -1) return dp[idx][d];
        
        int res = INT_MAX;
        int curMax = 0;
        
        for(int i=idx; i<jobDifficulty.size()-d+1; i++){
            curMax = max(curMax, jobDifficulty[i]);
            res = min(res, curMax+f(i+1, d-1, jobDifficulty, dp));
        }
        
        return dp[idx][d] = res;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        
        if(d > jobDifficulty.size()) return -1;
        
        vector<vector<int>> dp(jobDifficulty.size(), vector<int>(d+1, -1));
        return f(0, d, jobDifficulty, dp);
    }
};