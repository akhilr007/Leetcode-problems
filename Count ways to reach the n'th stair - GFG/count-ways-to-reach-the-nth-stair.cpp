//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int mod = (int)1e9+7;
    int solve(int n, vector<int> &dp){
        
        if(n == 1 or n == 2)
            return n;
        if(dp[n] != -1)
            return dp[n];
            
        int one_step = solve(n-1, dp);
        int two_step = solve(n-2, dp);
        
        return dp[n] = (one_step + two_step) % mod;
    }
    
    int countWays(int n)
    {
        if(n == 1 or n == 2)
            return n;
        vector<int> dp(n+1, 0);
        
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i=3; i<=n; i++)
            dp[i] = (dp[i-1] + dp[i-2]) % mod;
        
        return dp[n];
        
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends