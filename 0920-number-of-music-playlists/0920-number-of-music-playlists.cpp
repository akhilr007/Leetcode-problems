class Solution {
public:
    const int MOD = 1e9+7;
    long solve(int curSongCount, int uniqueSongCount, int n, int k, int goal, 
             vector<vector<int>>& dp){
        
        if(curSongCount == goal){
            return uniqueSongCount == n;
        }
        
        if(dp[curSongCount][uniqueSongCount] != -1)
            return dp[curSongCount][uniqueSongCount];
        
        long result = 0;
        
         // option-1 - to take new song
        if(n-uniqueSongCount>0)
            result += (n-uniqueSongCount) * solve(curSongCount+1, uniqueSongCount+1, n, k, goal, dp);
        
        // option-2 - to take old song
        if(uniqueSongCount-k>0)
            result += (uniqueSongCount-k) * solve(curSongCount+1, uniqueSongCount, n, k, goal, dp);
        
        return dp[curSongCount][uniqueSongCount] = result % MOD;
    }
    
    int numMusicPlaylists(int n, int goal, int k) {
        
        vector<vector<int>> dp(goal+1, vector<int>(n+1, -1));
        return solve(0, 0, n, k, goal, dp);
    }
};