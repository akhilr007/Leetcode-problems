class Solution {
public:
    int solve(int index, int m, bool alice_turn, vector<int>& piles, vector<int>& sum, 
             vector<vector<vector<int>>>& dp){
        
        if(index >= piles.size())
            return 0;
        
        if(dp[index][m][alice_turn] != -1)
            return dp[index][m][alice_turn];
        
        if(alice_turn == true){
            
            int ans = 0;
            for(int i=index; i<index+(2*m) && i<piles.size(); i++){
                ans = max(ans, query(index, i, sum) + solve(i+1, max(i-index+1, m), false, piles, sum, dp));
            }
            
            return dp[index][m][alice_turn] = ans;
        }
        else{
            int ans = 1e9;
            for(int i=index; i<index+(2*m) && i<piles.size(); i++){
                ans = min(ans, solve(i+1, max(i-index+1, m), true, piles, sum, dp));
            }
            
            if(ans == 1e9)
                ans = 0;
            return dp[index][m][alice_turn] = ans;
        }
    }
    int query(int l, int r, vector<int>& sum){
        
        if(l == 0){
            return sum[r];
        }
        
        return sum[r] - sum[l-1];
    }
    
    int stoneGameII(vector<int>& piles) {
        
        int n = piles.size();
        vector<int> sum(n, 0);
        
        for(int i=0; i<n; i++){
            if(i == 0){
                sum[i] = piles[i];
            }
            else{
                sum[i] = sum[i-1] + piles[i];
            }
        }
        
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (n+1, vector<int> (2, -1)));
        return solve(0, 1, true, piles, sum, dp);
    }
};