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
        int prev = arr[0]; // dp[i-1]
        int prev2 = 0; // dp[i-2]
        
        for(int i=1; i<n; i++){
            
            int notPick = 0 + prev;
            int pick = arr[i];
            if( i >= 2) pick = pick + prev2;
            
            int cur = max(pick , notPick);
            prev2 = prev;
            prev = cur;
        }
        
        return prev;
        
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