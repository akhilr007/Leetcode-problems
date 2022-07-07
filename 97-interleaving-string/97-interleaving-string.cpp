class Solution {
public:
    bool f(int i, int j, string& s1, string& s2, string& s3, 
           vector<vector<int>>& dp){
        
        if(i == 0 && j == 0) return true;
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(i>0 && s3[i+j-1] == s1[i-1]){
            if(j>0 && s3[i+j-1] == s2[j-1]){
                return dp[i][j] = f(i-1, j, s1, s2, s3, dp) || f(i, j-1, s1, s2, s3, dp);
            }
            else return dp[i][j] = f(i-1, j, s1, s2, s3, dp);
        }
        
        if(j>0 && s3[i+j-1] == s2[j-1]){
            return dp[i][j] = f(i, j-1, s1, s2, s3, dp);
        }
        else{
            return dp[i][j] = false;
        }
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        
        int n = s1.size();
        int m = s2.size();
        int o = s3.size();
        
        if (n + m != o) return false;
        if(s1.length() == 0){
            return s2 == s3;
        }
        else if(s2.length() == 0){
            return s1 == s3;
        }
        
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return f(n, m, s1, s2, s3, dp);
    }
};