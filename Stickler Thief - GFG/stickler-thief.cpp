// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int helper(int idx, int arr[], int n, vector<int>& dp){
        
        if(idx < 0) return 0;
        if(idx == 0) return arr[idx];
        if(dp[idx] != -1) return dp[idx];
        
        int notPick = 0 + helper(idx-1, arr, n, dp);
        int pick = arr[idx] + helper(idx-2, arr, n, dp);
        
        return dp[idx] = max(notPick, pick);
    }
    
    int FindMaxSum(int arr[], int n)
    {
        // vector<int> dp(n, 0);
        
        // dp[0] = arr[0];
        
        // for(int i=1; i<n; i++){
            
        //     int notPick = 0 + dp[i-1];
        //     int pick = 0;
        //     if(i>1) pick = arr[i] + dp[i-2];
            
        //     dp[i] = max(notPick, pick);
        // }
        
        // return max(dp[n-2], dp[n-1]);
        vector<int> dp(n, -1);
        return helper(n-1, arr, n, dp);
        
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends