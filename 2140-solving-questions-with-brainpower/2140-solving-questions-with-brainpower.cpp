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
    
    long long tabulation(vector<vector<int>>& questions){
        
        int n = questions.size();
        
        vector<long long> dp(n+1, 0);
        
        for(int index=n-1; index>=0; index--){
            
            long long take = questions[index][0];
            if(index+questions[index][1]+1 <= n)
                take = take + dp[index+(questions[index][1])+1];
        
            long long notTake = 0 + dp[index+1];

            dp[index] = max(take , notTake);
        }
        
        return dp[0];
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        
        int n = questions.size();
        
        vector<long long> dp(n, -1);
        return tabulation(questions);
    }
};