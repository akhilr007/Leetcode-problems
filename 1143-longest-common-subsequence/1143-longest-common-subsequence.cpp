class Solution {
public:
    // time complexity -> O(2^n)
    // space complexity -> O(n1 or n2)
    int solveRec(int i1, int i2, string& text1, string& text2){
        
        if(i1 < 0 || i2 < 0) return 0;
        
        if(text1[i1] == text2[i2]){
            return 1 + solveRec(i1-1, i2-1, text1, text2);
        }
        
        else{
            
            return max(solveRec(i1-1, i2, text1, text2), solveRec(i1, i2-1, text1, text2));
            
        }
        
    }
    
    // time complexity -> O(N*M)
    // space complexity -> O(N*M) + O(len of (s1) or len of (s2)) recursion stack
    int solveMem(int i1, int i2, string& text1, string& text2, 
                vector<vector<int>>& dp){
        
        if(i1 < 0 || i2 < 0) return 0;
        if(dp[i1][i2] != -1) return dp[i1][i2];
        
        if(text1[i1] == text2[i2]){
            return dp[i1][i2] = 1 + solveMem(i1-1, i2-1, text1, text2, dp);
        }
        
        else{
            
            return dp[i1][i2] = max(solveMem(i1-1, i2, text1, text2, dp), solveMem(i1, i2-1, text1, text2, dp));
            
        }
    }
    
    int solveTab(string& text1, string& text2){
        
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
        
                else{

                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

                }
            }   
        }
        
        return dp[n][m];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        
        return solveTab(text1, text2);
    }
};