class Solution {
public:
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2, int n, int m, vector<vector<int>>& dp){
        
        if(i == n || j == m) return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(nums1[i] == nums2[j]){
            int take = 1 + solve(i+1, j+1, nums1, nums2, n, m, dp);
            int not_take = solve(i, j+1, nums1, nums2, n, m, dp);
            
            return dp[i][j] = max(take, not_take);
        }
        
        return dp[i][j] = max(solve(i, j+1, nums1, nums2, n, m, dp), solve(i+1, j, nums1, nums2, n, m, dp));
    }
    
    int tabulation(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
        for(int i=n-1; i>=0; i--){
            
            for(int j=m-1; j>=0; j--){
                
                if(nums1[i] == nums2[j]){
                    int take = 1 + dp[i+1][j+1];
                    int not_take = dp[i][j+1];

                    dp[i][j] = max(take, not_take);
                }

                else dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
        
        return dp[0][0];
    }
    
    int optimal(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
        vector<int> front(m+1, 0), cur(m+1, 0);
        
        for(int i=n-1; i>=0; i--){
            
            for(int j=m-1; j>=0; j--){
                
                if(nums1[i] == nums2[j]){
                    int take = 1 + front[j+1];
                    int not_take = cur[j+1];

                    cur[j] = max(take, not_take);
                }

                else cur[j] = max(cur[j+1], front[j]);
            }
            
            front = cur;
        }
        
        return front[0];
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
        
        vector<vector<int>> dp(n, vector<int> (m, -1));
        
        return optimal(nums1, nums2);
    }
};