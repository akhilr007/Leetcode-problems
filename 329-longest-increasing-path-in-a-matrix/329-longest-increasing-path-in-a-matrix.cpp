class Solution {
private: int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
public:
    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        
        if(dp[i][j] > 0){
            return dp[i][j];
        }    
        
        int currLength = 1;
        
        for(int d=0; d<4; d++){
            int ni = i + dir[d][0];
            int nj = j + dir[d][1];
            
            if(ni < 0 || nj < 0 || ni >= matrix.size() || nj >= matrix[0].size()){
                continue;
            }
            
            if(matrix[i][j] >= matrix[ni][nj]){
                continue;
            }
            
            currLength = max(currLength, 1+dfs(ni, nj, matrix, dp));
        }
        
        dp[i][j] = currLength;
        return currLength;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        int maxLength=1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int currLength = dfs(i, j, matrix, dp);
                maxLength = max(maxLength, currLength);
            }
        }
        
        return maxLength;
    }
};