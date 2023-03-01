//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int f(int idx, vector<int>& height, int k, vector<int>& dp){
        
        if(idx == 0)
            return 0;
        if(dp[idx] != -1)
            return dp[idx];
            
        int res = 1e8;
        for(int i=1; i<=k; i++){
            
            if(idx - i >= 0){
                int jump = abs(height[idx] - height[idx - i]) + f(idx - i, height, k, dp);
                res = min(res, jump);
            }
            
        }
        
        
        
        return dp[idx] = res;
    }
    int minimizeCost(vector<int>& height, int n, int k) {
        
        vector<int> dp(n, 0);
        
        for(int i=1; i<n; i++){
            
            int res = 1e8;
            
            for(int j=1; j<=k; j++){
                
                
                if(i-j >= 0){
                    
                    int jump = abs(height[i] - height[i-j]) + dp[i-j];
                    res = min(res, jump);
                    
                }
            }
            
            dp[i] = res;
        }
        
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends