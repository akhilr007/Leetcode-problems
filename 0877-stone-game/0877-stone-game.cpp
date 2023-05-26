class Solution {
public:
    int solve(int l, int r, vector<int>& piles, bool alice_turn, vector<vector<int>>& dp){
        
        if(l >= r)
            return 0;
        if(dp[l][r] != -1)
            return dp[l][r];
        
        if(alice_turn == true){
            
            return dp[l][r] = max(solve(l+1, r, piles, false, dp) + piles[l], 
                       solve(l, r-1, piles, false, dp) + piles[r]);
        }
        else{
            //bob's turn
            
            return dp[l][r] = min(solve(l+1, r, piles, true, dp), solve(l, r-1, piles, true, dp));
        }
    }
    
    bool stoneGame(vector<int>& piles) {
        
        int n = piles.size();
        
        vector<vector<int>> dp(n, vector<int> (n, -1));
        int alice_stones_count = solve(0, n-1, piles, true, dp);
        
        int total_stones = accumulate(begin(piles), end(piles), 0);
        int bob_stones_count = total_stones - alice_stones_count;
        
        return alice_stones_count > bob_stones_count;
        
    }
};