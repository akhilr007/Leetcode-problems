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
    
    int tabulation(int d, int f, int t){
        
        vector<vector<int>> dp(d+1, vector<int>(t+1, 0));
        // base case -> if(dice == 0 and target == 0) return 1
        dp[0][0] = 1;
        
        for(int dice=1; dice<=d; dice++){
            for(int target=1; target<=t; target++){
                
                int ans=0;
                for(int i=1; i<=f; i++){
                    if(target-i >= 0)
                        ans = ((ans % MOD) + dp[dice-1][target-i] % MOD) % MOD;
                }
                
                dp[dice][target] = ans;
            }
        }
        
        return dp[d][t] % MOD;
    }
    
    int tabulationOptimisation(int d, int f, int t){
        
        vector<int> prev(t+1, 0), cur(t+1, 0);
        // base case -> if(dice == 0 and target == 0) return 1
        prev[0] = 1;
        
        for(int dice=1; dice<=d; dice++){
            for(int target=1; target<=t; target++){
                
                int ans=0;
                for(int i=1; i<=f; i++){
                    if(target-i >= 0)
                        ans = ((ans % MOD) + prev[target-i] % MOD) % MOD;
                }
                
                cur[target] = ans;
            }
            
            cur = prev;
        }
        
        return prev[t] % MOD;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        
        // two states changing -> dice and target
        //vector<vector<int>> dp(n+1, vector<int> (target+1, -1));
        return tabulation(n, k, target);
    }
};