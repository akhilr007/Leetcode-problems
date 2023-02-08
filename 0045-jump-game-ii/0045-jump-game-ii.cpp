class Solution {
    // TC -> O(n^n) SC -> O(1) recursion
    // TC -> O(N*N) SC -> O(N) + O(N)(stack space) memoization
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
    
/*
    int n=nums.size();
    vector<int> dp(n, -1);
    return f(0, nums, dp);
*/    
public:
    // TC -> O(N) SC -> O(1)
    int jump(vector<int>& nums) {
        
        int n=nums.size();
        
        int l=0, r=0;
        int minSteps=0;
        
        // if r reaches n-1 we have reached the destination
        while(r<n-1){
            int farthestJump=0;
            for(int i=l; i<=r; i++){
                farthestJump = max(farthestJump, i+nums[i]);
                
            }
            l = r+1;
            r = farthestJump;
            minSteps++;
        }
        
        return minSteps;
    }
};