class Solution {
public:
    int mod = 1e9+7;
    int solve(int i, int j, int k, vector<vector<int>>& apples, int m, int n, vector<vector<vector<int>>>& dp){
        
        // agar pure grid me less than k hai to zero ways se de paoge
        if(apples[i][j] < k){
            return 0;
        }
        
        if(k == 1){
            if(apples[i][j] >= k){
                return 1;
            }
            return 0;
        }
        
        if(dp[i][j][k] != -1)
            return dp[i][j][k];
        
        // horizontal cuts
        int ans = 0;
        for(int h=i+1; h<m; h++){
        
            int lower_slice_apples = apples[h][j];
            int upper_slice_apples = apples[i][j] - lower_slice_apples;
            
            if(upper_slice_apples >= 1 && lower_slice_apples >= k-1){
                
                ans = (ans % mod + solve(h, j, k-1, apples, m, n, dp) % mod) % mod;
            }
            
        }
        
        // vertical cuts
        for(int v=j+1; v<n; v++){
            
            int right_slice_apples = apples[i][v];
            int left_slice_apples = apples[i][j] - right_slice_apples;
            
            if(left_slice_apples >= 1 && right_slice_apples >= k-1){
                ans = (ans % mod + solve(i, v, k-1, apples, m, n, dp)%mod ) % mod;
            }
        }
        
        return dp[i][j][k] = ans;
    }
    
    int ways(vector<string>& pizza, int k) {
        
        int m = pizza.size();
        int n = pizza[0].size();
        
        vector<vector<int>> apples(m+1, vector<int>(n+1, 0));
        
        // make an array of apples
        // apples[i][j] -> no of apples in (i to m-1) and (j to n-1)
        for(int i=m-1; i>=0; i--){
            
            for(int j=n-1; j>=0; j--){
                
                apples[i][j] = apples[i][j+1];
                
                for(int l=i; l<m; l++){
                    
                    if(pizza[l][j] == 'A'){
                        apples[i][j] += 1;
                    }
                }
            }
        }
        
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>> (n+1, vector<int>(k+1, -1)));
        return solve(0, 0, k, apples, m, n, dp);
    }
};