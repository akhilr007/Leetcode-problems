class Solution {
public:
    int f(int idx, int prev, vector<int>& diff, vector<int>& dp){
        
        if(idx >= diff.size()) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        int notTake = f(idx+1, idx, diff, dp);
        
        int take=0;
        if(prev == -1 || (diff[idx] >= 0 && diff[prev] <= 0) || (diff[idx] <= 0 && diff[prev] >= 0)){
            take = 1 + f(idx+1, idx, diff, dp);
        }
        
        return dp[idx] = max(take, notTake);
    }
    
    int wiggleMaxLength(vector<int>& nums) {
        
        if(nums.size() < 2) return nums.size();
        
        vector<int> diff;
        for(int i=1; i<nums.size(); i++){
            
            int val = nums[i] - nums[i-1];
            if(val != 0)
                diff.push_back(val);
        }
        
        int n = diff.size();
        vector<int> dp(n+1, -1);
        return 1 + f(0, -1, diff, dp);
    }
};