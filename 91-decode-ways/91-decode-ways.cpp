class Solution {
public:
    int helper(string& s, int n, vector<int>& dp){
        
        if(n == 0){
            return 1;
        }
        
        if(dp[n-1] != -1) return dp[n];
        
        int count = 0;
        if(s[n-1] != '0'){
            count += helper(s, n-1, dp);
        }
        
        if(n>1 && stoi(s.substr(n-2, 2)) >= 10 && stoi(s.substr(n-2, 2)) <= 26){
            count += helper(s, n-2, dp);
        }
        
        return dp[n] = count;
    }
    
    int numDecodings(string s) {
        
        if(s[0] == '0') return 0;
        int n = s.length();
        vector<int> dp(n+1, -1);
        
        return helper(s, n, dp);
        
    }
};