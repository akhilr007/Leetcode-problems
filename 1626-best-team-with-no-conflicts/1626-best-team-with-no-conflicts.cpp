class Solution {
public:
    int solve(int i, int j, vector<pair<int, int>>& arr, int n,
             vector<vector<int>>& dp){
        
        if(i == n)
            return 0;
        if(dp[i][j+1] != -1)
            return dp[i][j+1];
        
        int m_score = 0, m_age = 0;
        int score = arr[i].first, age = arr[i].second;
        
        int res = 0;
        
        if(j >= 0){
            m_score = arr[j].first;
            m_age = arr[j].second;
        }
        
        if (age >= m_age)
            res = score + solve(i+1, i, arr, n, dp) ;
        
        return dp[i][j+1] = max(res, solve(i+1, j, arr, n, dp));
    }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        
        int n = scores.size();
        vector<pair<int, int>> arr;
        for(int i=0; i<n; i++){
            arr.push_back({scores[i], ages[i]});
        }
        
        sort(begin(arr), end(arr));
        
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return solve(0, -1, arr, n, dp);
    }
};