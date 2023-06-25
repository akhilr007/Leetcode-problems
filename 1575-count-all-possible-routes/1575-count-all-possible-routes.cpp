class Solution {
public:
    const int MOD = (int)1e9 + 7;
    int solve(int index, int fuel, int finish, vector<int>& locations, vector<vector<int>>& dp){
        
        if(fuel < 0)
            return 0;
        
        if(dp[index][fuel] != -1)
            return dp[index][fuel];
        
        int total = index == finish ? 1 : 0;
        for(int j=0; j<locations.size(); j++){
            
            if(j != index){
                
                int remFuel = fuel - abs(locations[j] - locations[index]);
                total = (total + solve(j, remFuel, finish, locations, dp)) % MOD;
            }
        }
        
        return dp[index][fuel] = total;
    }
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        
        int n = locations.size();
        
        vector<vector<int>> dp(n, vector<int> (201, -1));
        return solve(start, fuel, finish, locations, dp);
    }
};