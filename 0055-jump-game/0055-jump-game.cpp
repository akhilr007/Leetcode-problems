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
    
    // time complexity -> O(n * n)
    // space complexity -> O(n)
    bool solveTabDP(vector<int>& nums){
        
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
    
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        int maxReachable = 0;
        
        for(int i=0; i<n; i++){
            
            if(i > maxReachable) return false;
            
            maxReachable = max(maxReachable, i + nums[i]);
        }
        return true;
    }
};