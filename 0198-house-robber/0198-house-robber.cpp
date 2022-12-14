class Solution {
public:
    // time complexity -> 2^m
    // space complexity -> O(n)
    int solveRec(int idx, vector<int>& nums){
        
        if(idx<0) return 0;
        if(idx == 0) return nums[idx];
        
        int notPick = 0 + solveRec(idx-1, nums);
        int pick = nums[idx] + solveRec(idx-2, nums);
        
        return max(notPick, pick);
    }
    
    // time complexity -> O(n)
    // space complexity -> O(n for dp cache + n for recursion stack space)
    int solveMem(int idx, vector<int>& nums, vector<int>& dp){
        
        if(idx<0) return 0;
        if(idx == 0) return nums[idx];
        if(dp[idx] != -1) return dp[idx];
        
        int notPick = 0 + solveMem(idx-1, nums, dp);
        int pick = nums[idx] + solveMem(idx-2, nums, dp);
        
        return dp[idx] = max(notPick, pick);
    }
    
    int solveTab(vector<int>& nums, int n){
        
        if(n == 1) return nums[0];
        
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        
        for(int i=2; i<=n; i++){
            
            int pick = nums[i-1] + dp[i-2];
            int notPick = 0 + dp[i-1];
            
            dp[i] = max(pick, notPick);
        }
        
        return dp[n];
    }
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        return solveTab(nums, n);
    }
};