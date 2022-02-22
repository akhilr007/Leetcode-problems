class Solution {
public:
    
    bool f(int idx, int target, vector<int>& nums, vector<vector<int>>& dp){
        
        if(target == 0) return true;
        if(idx==0) return nums[idx] == target;
        
        if(dp[idx][target] != -1) return dp[idx][target];
        
        bool notTake = f(idx-1, target, nums, dp);
        bool take = false;
        
        if(nums[idx]<=target) take = f(idx-1, target-nums[idx], nums, dp);
        
        return dp[idx][target] = notTake|take;
    }
    
    bool canPartition(vector<int>& nums) {
        
        int n=nums.size();
        
        int totalSum=0;
        for(auto val: nums) totalSum += val;
        
        if(totalSum%2) return false;
        
        int target = totalSum/2;
        
        // vector<vector<bool>> dp(n, vector<bool> (target+1, 0));
        // return f(n-1, target, nums, dp);
        
        vector<int> prev(target+1, 0), cur(target+1, 0);
        
        prev[0] = cur[0] = true;
        
        if(nums[0] <= target) prev[nums[0]] = true;
        
        // for(int i=0; i<n; i++) dp[i][0] = true;
        // if(nums[0] <= target) dp[0][nums[0]] = true;
        
        for(int i=1; i<n; i++){
            for(int t=1; t<=target; t++){
                
                bool notTake = prev[t];
                bool take = false;
                if(nums[i] <= t) take = prev[t-nums[i]];
                
                cur[t] = notTake | take;
            }
            prev = cur;
        }
        
        return prev[target];
    }
};