class Solution {
public:
    bool solve(int i, int j, string&p, string& s, vector<vector<int>>& dp){

        // base case

        // if both strings have exhaust 
        if(i<0 && j<0) return true;

        // if p string have been exhaust & s string still not empty
        if(i<0 && j>=0) return false;

        // if s string have been exhaust & p string sill not empty
        // true only if all chars are '*' otherwise false
        if(j<0 && i>=0){
            for(int ii=0; ii<=i; ii++){
                if(p[ii] != '*')
                    return false;
            }

            return true;
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        if(p[i] == s[j] || p[i] == '?')
            return dp[i][j] = solve(i-1, j-1, p, s, dp);

        if(p[i] == '*')
        {
            // two option 
            // '*' -> means nothing and '*' -> match a char or two char ...
            return dp[i][j] = solve(i-1, j, p, s, dp) || solve(i, j-1, p, s, dp);
        }

        // if no match
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p){

        int n = p.size();
        int m = s.size();

        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(n-1, m-1, p, s, dp);
    }
};