class Solution {
public:
    int solve(int i, int j, vector<int>& cuts, vector<vector<int>>& dp){
        
        if(i > j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int result = INT_MAX;
        
        for(int ind=i; ind<=j; ind++){
            
            int cost = cuts[j+1] - cuts[i-1] + solve(i, ind-1, cuts, dp) + solve(ind+1, j, cuts, dp);
            result = min(result, cost);
        }
        
        return dp[i][j] = result;
    }
    
    int tabulation(vector<int>& cuts){
        
        vector<vector<int>> dp(size(cuts), vector<int> (size(cuts)));
        
        
        int size = cuts.size()-2;
        
        for(int i=size; i>=1; i--){
            for(int j=1; j<=size; j++){
                
                if(i > j)
                    continue;
                
                int result = INT_MAX;
                
                for(int ind=i; ind<=j; ind++){
                    
                    int cost = cuts[j+1] - cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];
                    result = min(result, cost);
                }
                
                dp[i][j] = result;
            }
        }
        
        return dp[1][size];
    }
    
    int minCost(int n, vector<int>& cuts) {
        
        cuts.push_back(n);
        cuts.insert(begin(cuts), 0);
        
        sort(begin(cuts), end(cuts));
        
        vector<vector<int>> dp(size(cuts), vector<int>(size(cuts), -1));
        return tabulation(cuts);
    }
};