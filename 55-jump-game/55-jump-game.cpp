class Solution {
private:
    // TC -> O(n) SC -> O(n) memoization
    bool f(int i, vector<int>& nums, int n, vector<int>& dp){
        
        if(i==n-1) return true;
        
        if(dp[i] != -1) return dp[i];
        
        bool ans = false;    
        for(int j=1; j<=nums[i] && j<n; j++){
            ans = ans | f(i+j, nums, n, dp);
            
            if(ans) break;
        }
        
        return dp[i] = ans;
    }
/*    
    vector<int> dp(n, -1);
    return f(0, nums, n, dp);
*/
public:
    
    
    bool canJump(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> dp(n, -1);
        return f(0, nums, n, dp);
    }
};