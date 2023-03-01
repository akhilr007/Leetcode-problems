//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int f(int idx, vector<int>& height, vector<int>& dp){
        
        if(idx == 0) return 0;
        if(dp[idx] != -1)
            return dp[idx];
        
        int one_step = abs(height[idx] - height[idx-1]) + f(idx -1, height, dp);
        
        int two_step = 1e8;
        if(idx > 1) two_step = abs(height[idx] - height[idx-2]) + f(idx-2, height, dp);
        
        return dp[idx] = min(one_step, two_step);
    }
    int minimumEnergy(vector<int>& height, int n) {
       
       vector<int> dp(n, 0);
       
       for(int i=1; i<n; i++){
           
           int one_step = dp[i-1] + abs(height[i] - height[i-1]);
           int two_step = 1e8;
           if(i > 1) two_step = dp[i-2] + abs(height[i] - height[i-2]);
           
           dp[i] = min(one_step, two_step);
       }
       
       return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends