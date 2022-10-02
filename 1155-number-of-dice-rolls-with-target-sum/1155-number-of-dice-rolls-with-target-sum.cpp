class Solution {
private:
    int MOD = 1e9+7;
public:
    int f(int dice, int faces, int target){
        
        if(target < 0) return 0;
        if(dice != 0 && target == 0) return 0;
        if(target != 0 && dice == 0) return 0;
        if(dice == 0 && target == 0) return 1;
        
        int ans=0;
        for(int i=1; i<=faces; i++){
            ans = ((ans % MOD) + f(dice-1, faces, target-i) % MOD) % MOD;
        }
        
        return ans % MOD;
    }
    
    int fMemoization(int dice, int faces, int target, vector<vector<int>>& dp){
        
        if(target < 0) return 0;
        if(dice != 0 && target == 0) return 0;
        if(target != 0 && dice == 0) return 0;
        if(dice == 0 && target == 0) return 1;
        
        if(dp[dice][target] != -1) return dp[dice][target];
        
        int ans=0;
        for(int i=1; i<=faces; i++){
            ans = ((ans % MOD) + fMemoization(dice-1, faces, target-i, dp) % MOD) % MOD;
        }
        
        return dp[dice][target] = ans % MOD;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        
        // two states changing -> dice and target
        vector<vector<int>> dp(n+1, vector<int> (target+1, -1));
        return fMemoization(n, k, target, dp);
    }
};