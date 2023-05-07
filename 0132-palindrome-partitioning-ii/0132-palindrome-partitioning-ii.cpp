class Solution {
public:
    bool isPalindrome(int i, int j, string& s){
        
        while(i<j){
            
            if(s[i] != s[j])
                return false;
            
            i++;
            j--;
        }
        
        return true;
    }
    
    int solve(int i, int n, string& s, vector<int>& dp){
        
        if(i == n)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int minCuts = 1e9;
        for(int j=i; j<n; j++){
            
            if(isPalindrome(i, j, s)){
                int cost = 1 + solve(j+1, n, s, dp);
                minCuts = min(minCuts, cost);
            }
                
        }
        
        return dp[i] = minCuts;
    }
    
    int tabulation(string s){
        
        int n = s.size();
        vector<int> dp(n+1, 0);
        
        for(int i=n-1; i>=0; i--){
            
            int minCuts = 1e9;
            
            for(int j=i; j<n; j++){
                
                if(isPalindrome(i, j, s)){
                    int cost = 1 + dp[j+1];
                    minCuts = min(minCuts, cost);
                }
            }
            
            dp[i] = minCuts;
        }
        
        return dp[0] - 1;
    }
    
    int minCut(string s) {
        
        int n = s.size();
        
        return tabulation(s);
        vector<int> dp(n, -1);
        return solve(0, n, s, dp) - 1; // it makes cuts then go to end so -1 from ans;
    }
};