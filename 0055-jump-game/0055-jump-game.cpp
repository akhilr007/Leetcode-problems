class Solution {
public:
    // time complexity -> O(k ^ n) -> O(n) for memoization
    // space complexity -> O(n) 
    bool solveRec(int idx, vector<int>& nums, int n, vector<int>& t){
        
        if(idx == n-1) return true;
        if(t[idx] != -1) return t[idx];
        
        for(int jump=1; jump<=nums[idx]; jump++){
            if(solveRec(idx+jump, nums, n, t)) return t[idx] = true;
        }
        
        return t[idx] = false;
    }
    
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        
        for(int i=1; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(dp[j] == 1 && j + nums[j] >= i){
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[n-1];
    }
};