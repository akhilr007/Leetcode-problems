class Solution {
public:
    int dp[1001][1003];
    int dfs(int i, int d, vector<int>& nums){
        
        if(i<0)
            return 0;
        
        if(dp[i][d+501] != -1)
            return dp[i][d+501];
        
        int ans = 0;
        for(int k=i-1; k>=0; k--){
            
            if(nums[i] - nums[k] == d){
                ans = max(ans, 1+dfs(k, d, nums));
            }
        }
        return dp[i][d+501] = ans;
    }
    
    /*
        memset(dp, -1, sizeof dp);
        
        int result = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                
                int d = nums[j] - nums[i];
                result = max(result, 2 + dfs(i, d, nums));
            }
        }
        
        return result;
    */
    
    int longestArithSeqLength(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<vector<int>> dp(n, vector<int> (1001, 0));
        //dp[i][diff] -> longest arithmetic sequence ending at i with difference diff
        int result = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                
                int d = (nums[i] - nums[j]) + 500;
                
                dp[i][d] = dp[j][d] > 0 ? dp[j][d] + 1 : 2;
                result = max(result, dp[i][d]);
            }
        }
        return result;
    }
};