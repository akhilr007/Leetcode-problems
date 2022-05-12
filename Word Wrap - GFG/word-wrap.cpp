// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int f(int i, int rem, vector<int>& nums, int& k,
    vector<vector<int>>& dp){
        
        if(i == nums.size()) {
            return 0;
        }
        
        if(dp[i][rem] != -1){
            return dp[i][rem];
        }
        
        int cost;
        if(nums[i] > rem){
            cost = (rem+1)*(rem+1) + f(i+1, k-nums[i]-1 < 0 ? 0 : k-nums[i]-1, nums, k, dp);
        }
        else if(nums[i] == rem){
            cost = min(f(i+1, k, nums, k, dp),
            (rem+1)*(rem+1) + f(i+1, k-nums[i]-1, nums, k, dp));
        }
        else{
            int choice1 = f(i+1, rem-nums[i]-1, nums, k, dp);
            int choice2 = (rem+1)*(rem+1) + f(i+1, k-nums[i]-1, nums, k, dp);
            cost = min(choice1, choice2);
        }
        
        return dp[i][rem] = cost;
    }
    
    int solveWordWrap(vector<int>nums, int k) 
    { 
        int rem=k;
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return f(0, rem, nums, k, dp);
    } 
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends