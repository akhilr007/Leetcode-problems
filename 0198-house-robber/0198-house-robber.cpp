class Solution {
public:
    int solveRec(int idx, vector<int>& nums){
        
        if(idx<0) return 0;
        if(idx == 0) return nums[idx];
        
        int notPick = 0 + solveRec(idx-1, nums);
        int pick = nums[idx] + solveRec(idx-2, nums);
        
        return max(notPick, pick);
    }
    
    int solveMem(int idx, vector<int>& nums, vector<int>& dp){
        
        if(idx<0) return 0;
        if(idx == 0) return nums[idx];
        if(dp[idx] != -1) return dp[idx];
        
        int notPick = 0 + solveMem(idx-1, nums, dp);
        int pick = nums[idx] + solveMem(idx-2, nums, dp);
        
        return dp[idx] = max(notPick, pick);
    }
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> dp(n, -1);
        int last = solveMem(n-1, nums, dp);
        int secondLast = solveMem(n-2, nums, dp);
        
        return max(last, secondLast);
    }
};