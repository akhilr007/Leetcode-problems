//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod = (int)1e9 + 7;
    int solve(int idx, vector<int>& arr, int target,
    vector<vector<int>>& dp){
        
        if(idx == 0){
            if(target == 0 and arr[0] == 0)
                return 2;
            else if(target == 0 or arr[0] == target)
                return 1;
            else
                return 0;
        }
        if(dp[idx][target] != -1)
            return dp[idx][target];
        
        int notTake = solve(idx - 1, arr, target, dp);
        int take = 0;
        if(arr[idx] <= target)
            take = solve(idx - 1, arr, target - arr[idx], dp);
            
        return dp[idx][target] = (take + notTake) % mod;
    }
    
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int total_sum = 0;
        for(auto it: arr) total_sum += it;
        
        if(total_sum - d < 0 or (total_sum - d) % 2)
            return 0;
        
        vector<vector<int>> dp(n, vector<int>(total_sum + 1, -1));
        return solve(n-1, arr, (total_sum - d) / 2, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends