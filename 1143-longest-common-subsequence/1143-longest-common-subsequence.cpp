class Solution {
public:
    int solveRec(int i1, int i2, string& text1, string& text2, 
                vector<vector<int>>& dp){
        
        if(i1 < 0 || i2 < 0) return 0;
        if(dp[i1][i2] != -1) return dp[i1][i2];
        
        if(text1[i1] == text2[i2]){
            return dp[i1][i2] = 1 + solveRec(i1-1, i2-1, text1, text2, dp);
        }
        
        if(text1[i1] != text2[i2]){
            
            return dp[i1][i2] = max(solveRec(i1-1, i2, text1, text2, dp), solveRec(i1, i2-1, text1, text2, dp));
            
        }
        
        return 0;
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        
        int n1 = text1.length();
        int n2 = text2.length();
        
        vector<vector<int>> dp(n1, vector<int> (n2, -1));
        return solveRec(n1-1, n2-1, text1, text2, dp);
    }
};