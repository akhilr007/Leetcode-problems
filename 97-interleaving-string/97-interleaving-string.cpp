class Solution {
public:
    bool f(int i, int j, int k, string& s1, string& s2, string& s3, 
          vector<vector<vector<int>>>& dp){
        
        if(k == 0 && i == 0 && j == 0) return true;
        
        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }
        
        if(i>0 && k>0 && s3[k-1] == s1[i-1]){
            if(j>0 && k>0 && s3[k-1] == s2[j-1]){
                return dp[i][j][k] = f(i-1, j, k-1, s1, s2, s3, dp) || f(i, j-1, k-1, s1, s2, s3, dp);
            }
            else return dp[i][j][k] = f(i-1, j, k-1, s1, s2, s3, dp);
        }
        
        if(j>0 && k>0 && s3[k-1] == s2[j-1]){
            return dp[i][j][k] = f(i, j-1, k-1, s1, s2, s3, dp);
        }
        else{
            return dp[i][j][k] = false;
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
        
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (m+1, vector<int>(o+1, -1)));
        return f(n, m, o, s1, s2, s3, dp);
    }
};