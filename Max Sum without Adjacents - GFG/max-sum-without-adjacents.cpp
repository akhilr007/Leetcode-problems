//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int f(int idx, int* arr,  vector<int>& dp){
	    
	    if(idx < 0) return 0;
	    if(idx == 0) return arr[idx];
	    if(dp[idx] != -1)
	        return dp[idx];
	    
	    int take = arr[idx] + f(idx - 2, arr, dp);
	    int not_take = 0 + f(idx - 1, arr, dp);
	    
	    return dp[idx] = max(take, not_take);
	}
	int findMaxSum(int *arr, int n) {
	    
	    vector<int> dp(n, 0);
	   // return f(n-1, arr, dp);
	   
	   dp[0] = arr[0];
	   
	   for(int i=1; i<n; i++){
	       
	       int not_take =  0 + dp[i-1];
	       int take = arr[i];
	       if(i>1) take += dp[i-2];
	       
	       dp[i] = max(not_take, take);
	   }
	   
	   return dp[n-1];
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends