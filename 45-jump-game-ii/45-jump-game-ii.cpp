class Solution {
private:
    int f(int i, vector<int>& nums, vector<int>& dp){
        
        if(i >= nums.size()-1){
            return 0;
        }
        
        if(dp[i] != -1) return dp[i];
        
        int mini=1e8;
        for(int j=1; j<=nums[i] && j<nums.size(); j++){
            int steps = 1 + f(i+j, nums, dp);
            mini = min(steps, mini);
        }
        
        return dp[i] = mini;
    }
    
public:
    int jump(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> dp(n, -1);
        return f(0, nums, dp);
    }
};