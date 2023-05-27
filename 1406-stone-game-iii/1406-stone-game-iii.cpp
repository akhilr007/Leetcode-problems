class Solution {
public:
    int solve(int index, bool alice_turn, vector<int>& stoneValue,vector<vector<int>>& dp){
        
        if(index >= stoneValue.size())
            return 0;
        
        if(dp[index][alice_turn] != -1)
            return dp[index][alice_turn];
        
        int ans;
        int sum=0;
        
        if(alice_turn == true){
            
            ans = -1e9;
            for(int i=index; i<index + 3 && i<stoneValue.size(); i++){
                
                sum += stoneValue[i];
                ans = max(ans, sum + solve(i+1, false, stoneValue, dp));
            }
            
            return dp[index][alice_turn] = ans;
        }
        else{
            
            ans = 1e9;
            for(int i=index; i<index + 3 && i<stoneValue.size(); i++){
                
                ans = min(ans, solve(i+1, true, stoneValue, dp));
            }
            
            return dp[index][alice_turn] = ans;
        }
    }
    
    string stoneGameIII(vector<int>& stoneValue) {
        
        int n = stoneValue.size();
        
        vector<vector<int>> dp(n, vector<int> (2, -1));
        int alice_points = solve(0, true, stoneValue, dp);
        
        
        int bob_points = accumulate(begin(stoneValue), end(stoneValue), 0) - alice_points;
        
        if(alice_points > bob_points){
            return "Alice";
        }
        else if(alice_points < bob_points){
            return "Bob";
        }
        else{
            return "Tie";
        }
    }
};