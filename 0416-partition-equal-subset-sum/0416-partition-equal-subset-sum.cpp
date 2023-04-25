class Solution {
public:
    bool isSubsetSumK(int index, int target, vector<int>& nums, vector<vector<int>>& dp)
    {
        if(target == 0)
            return true;
        
        if(index == 0)
            return nums[index] == target;
        
        if(dp[index][target] != -1)
            return dp[index][target];
        
        bool not_taken = isSubsetSumK(index-1, target, nums, dp);
        bool taken = false;
        if(nums[index] <= target)
            taken = isSubsetSumK(index-1, target-nums[index], nums, dp);
        
        return dp[index][target] = not_taken || taken;
    }
    
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        
        int total_sum = accumulate(begin(nums), end(nums), 0);
        
        if(total_sum % 2)
            return false;
        
        int target = total_sum / 2;
        
        vector<int> prev(target+1, 0), cur(target+1, 0);
        
        for(int index=0; index<n; index++)
            prev[0] = 1;
        
        if(nums[0] <= target)
            prev[nums[0]] = 1;
        
        for(int index=1; index<n; index++)
        {
            for(int sum=1; sum<=target; sum++)
            {
                
                bool not_taken = prev[sum];
                bool taken = false;
                if(nums[index] <= sum)
                    taken = prev[sum-nums[index]];
                
                cur[sum] = not_taken || taken;
            }
            
            prev = cur;
        }
        
        return prev[target];
    }
};