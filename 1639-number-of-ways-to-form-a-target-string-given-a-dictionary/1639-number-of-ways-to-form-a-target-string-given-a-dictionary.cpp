class Solution {
public:
    int targetLength, wordLength;
    int MOD=1e9+7;
    
    int solve(int i, int j, vector<string>& words, string& target, vector<vector<long long>>& freqOfCharsAtIndex,
              vector<vector<int>>& dp)
    {
        
        if(i >= targetLength)
            return 1;
        if(j >= wordLength)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int not_taken = solve(i, j+1, words, target, freqOfCharsAtIndex, dp) % MOD;
        
        int taken = ((freqOfCharsAtIndex[target[i]-'a'][j]) % MOD * solve(i+1, j+1, words, target, freqOfCharsAtIndex, dp) % MOD) % MOD;
        
        return dp[i][j] = (not_taken + taken) % MOD;
    }
    
    int numWays(vector<string>& words, string target) {
        
        targetLength = target.length();
        wordLength = words[0].length();
        
        vector<vector<long long>> freqOfCharsAtIndex(26, vector<long long> (wordLength, 0));
        
        for(int col=0; col<wordLength; col++){
            for(string& word: words){
                
                char ch = word[col];
                
                freqOfCharsAtIndex[ch-'a'][col]++;
            }
        }
        
        vector<vector<int>> dp(targetLength, vector<int> (wordLength, -1));
        return solve(0, 0, words, target, freqOfCharsAtIndex, dp);
    }
};