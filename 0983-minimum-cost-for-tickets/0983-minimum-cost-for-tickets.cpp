class Solution {
public:
    int solve(int index, vector<int>& days, vector<int>& costs, int n,
             vector<int>& dp){
        
        if(index >= n)
            return 0;
        if(dp[index] != -1)
            return dp[index];
        
        int day1Pass = costs[0] + solve(index+1, days, costs, n, dp);
        
        int i;
        for(i=index; i<n && days[i] < days[index] + 7; i++);
        
        int day7Pass = costs[1] + solve(i, days, costs, n, dp);
        
        for(i=index; i<n && days[i] < days[index] + 30; i++);
        
        int day30Pass = costs[2] + solve(i, days, costs, n, dp);
        
        return dp[index] = min(day1Pass, min(day7Pass, day30Pass));
    }
    
    int tabulation(vector<int>& days, vector<int>& costs){
        
        int n = days.size();
        vector<int> dp(n+1, 1e9);
        dp[n] = 0;
        
        for(int index=n-1; index>=0; index--){
            
            int day1Pass = costs[0] + dp[index+1];
        
            int i;
            for(i=index; i<n && days[i] < days[index] + 7; i++);

            int day7Pass = costs[1] + dp[i];

            for(i=index; i<n && days[i] < days[index] + 30; i++);

            int day30Pass = costs[2] + dp[i];

            dp[index] = min(day1Pass, min(day7Pass, day30Pass));
        }
        
        return dp[0];
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int ans = 0;
        queue<pair<int, int>> monthly;
        queue<pair<int, int>> weekly;
        
        for(int day: days){
            
            while(!monthly.empty() && monthly.front().first + 30 <= day){
                monthly.pop();
            }
            
            while(!weekly.empty() && weekly.front().first + 7 <= day){
                weekly.pop();
            }
            
            monthly.push({day, ans + costs[2]});
            weekly.push({day, ans + costs[1]});
            
            ans = min({ans+costs[0], monthly.front().second, weekly.front().second});
        }
        
        return ans;
    }
};