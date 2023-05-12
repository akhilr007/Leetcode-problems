class Solution {
public:
    long long solve(int index, vector<vector<int>>& questions, int n, vector<long long>& dp){
        
        if(index >= n)
            return 0;
        
        if(dp[index] != -1)
            return dp[index];
        
        
        long long take = questions[index][0] + solve(index+questions[index][1]+1, questions, n, dp);
        
        long long notTake = 0 + solve(index+1, questions, n, dp);
        
        return dp[index] = max(take , notTake);
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        
        int n = questions.size();
        
        vector<long long> dp(n, -1);
        return solve(0, questions, n, dp);
    }
};